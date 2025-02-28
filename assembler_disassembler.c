#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 50
#define MAX_MNEMONICS 7

// Opcode Mapping
const char *mnemonics[MAX_MNEMONICS] = {"HALT", "LOAD", "STORE", "ADD", "SUB", "MUL", "DIV"};
const char *opcodes[MAX_MNEMONICS] = {"000", "001", "100", "011", "010", "101", "110"};

// Function to trim leading/trailing spaces
void trim(char *str) {
    int i, start = 0, end = strlen(str) - 1;
    while (isspace(str[start])) start++;
    while (end > start && isspace(str[end])) end--;
    for (i = start; i <= end; i++) str[i - start] = str[i];
    str[i - start] = '\0';
}

// Function to find opcode for a mnemonic
const char* get_opcode(const char *mnemonic) {
    for (int i = 0; i < MAX_MNEMONICS; i++) {
        if (strcmp(mnemonics[i], mnemonic) == 0) {
            return opcodes[i];
        }
    }
    return NULL;
}

// Function to find mnemonic for an opcode
const char* get_mnemonic(const char *opcode) {
    for (int i = 0; i < MAX_MNEMONICS; i++) {
        if (strcmp(opcodes[i], opcode) == 0) {
            return mnemonics[i];
        }
    }
    return NULL;
}

// Assembler: Convert Assembly to Machine Code
void assemble(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");
    if (!in || !out) {
        printf("Error: Unable to open file.\n");
        return;
    }

    char line[MAX_LINE];
    int line_num = 0;

    while (fgets(line, MAX_LINE, in)) {
        line_num++;
        trim(line);
        if (strlen(line) == 0) continue;

        char mnemonic[MAX_LINE];
        int operand;
        if (sscanf(line, "%s %d", mnemonic, &operand) < 1) {
            printf("Error: Invalid or missing operand at line %d.\n", line_num);
            continue;
        }
        
        const char *opcode = get_opcode(mnemonic);
        if (!opcode) {
            printf("Error: Invalid mnemonic '%s' at line %d.\n", mnemonic, line_num);
            continue;
        }
        
        if (strcmp(mnemonic, "HALT") == 0) operand = 0;
        fprintf(out, "%s %08d\n", opcode, operand);
    }
    fclose(in);
    fclose(out);
    printf("Assembly to Machine Code conversion complete.\n");
}

// Disassembler: Convert Machine Code to Assembly
void disassemble(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");
    if (!in || !out) {
        printf("Error: Unable to open file.\n");
        return;
    }
    
    char line[MAX_LINE];
    int line_num = 0;
    
    while (fgets(line, MAX_LINE, in)) {
        line_num++;
        trim(line);
        if (strlen(line) == 0) continue;
        
        char opcode[4], operand[9];
        if (sscanf(line, "%3s %8s", opcode, operand) < 2) {
            printf("Error: Invalid machine code format at line %d.\n", line_num);
            continue;
        }
        
        const char *mnemonic = get_mnemonic(opcode);
        if (!mnemonic) {
            printf("Error: Invalid opcode '%s' at line %d.\n", opcode, line_num);
            continue;
        }
        
        int operand_value = strtol(operand, NULL, 2);
        fprintf(out, "%s %d\n", mnemonic, operand_value);
    }
    fclose(in);
    fclose(out);
    printf("Machine Code to Assembly conversion complete.\n");
}

// Main Menu
int main() {
    int choice;
    char input_file[MAX_LINE];
    char output_file[MAX_LINE];

    while (1) {
        printf("\nSelect an operation:\n");
        printf("1. Assemble (Assembly to Machine Code)\n");
        printf("2. Disassemble (Machine Code to Assembly)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        if (choice == 3) {
            printf("Exiting...\n");
            break;
        }

        printf("Enter input file name: ");
        scanf("%s", input_file);
        getchar(); // Consume newline
        
        if ((choice == 1 && strncmp(input_file, "assembly_test", 13) != 0) || 
            (choice == 2 && strncmp(input_file, "machine_test", 12) != 0)) {
            printf("Error: Invalid file name for selected operation.\n");
            continue;
        }
        
        snprintf(output_file, sizeof(output_file), "output_%c.txt", input_file[strlen(input_file) - 5]);
        
        if (choice == 1) {
            assemble(input_file, output_file);
        } else if (choice == 2) {
            disassemble(input_file, output_file);
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
