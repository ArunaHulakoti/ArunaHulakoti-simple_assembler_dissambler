# ArunaHulakoti-simple_assembler_dissambler
A C program that converts assembly to machine code and vice versa, with error handling, automated test cases, and structured output formatting. 

# Assembler and Disassembler Program

## Overview

This program converts assembly language instructions into machine code (Assembler) and also converts machine code back into assembly language (Disassembler). It includes error handling and supports multiple test cases to ensure robustness.

## Features

✅ Converts Assembly to Machine Code (Assembler)\
✅ Converts Machine Code to Assembly (Disassembler)\
✅ Handles errors (invalid mnemonics, missing operands, invalid opcodes, etc.)\
✅ Trims extra spaces and formats output correctly\
✅ Supports automated test cases

---

## File Naming Convention

- **Input Files:** Assembly files are named as `assembly_testX.txt`, and machine code files are named as `machine_testX.txt`, where `X` is the test case number.
- **Output Files:** The output files are named as `output_X.txt`, where `X` matches the respective input file number.

Example:

- Input: `assembly_test1.txt` → Output: `output_1.txt`
- Input: `machine_test2.txt` → Output: `output_2.txt`

---

## Compilation & Execution

### **1. Compile the Code**

If using `gcc` on Linux/macOS:

```bash
gcc assembler_disassembler.c -o assembler_disassembler
```

If using `MinGW` on Windows:

```bash
gcc assembler_disassembler.c -o assembler_disassembler.exe
```

### **2. Run the Program**

#### **To Assemble (Convert Assembly to Machine Code)**

```bash
./assembler_disassembler
```

- Enter `1` when prompted.
- Provide the input filename (e.g., `assembly_test1.txt`).
- The machine code will be saved in `output_1.txt`.

#### **To Disassemble (Convert Machine Code to Assembly)**

```bash
./assembler_disassembler
```

- Enter `2` when prompted.
- Provide the input filename (e.g., `machine_test2.txt`).
- The assembly output will be saved in `output_2.txt`.

---


## Notes

- The program is optimized for efficiency and correct error handling.
- Ensure the input files exist in the same directory before running.
- The program will automatically generate the correct output files with appropriate names.

---



