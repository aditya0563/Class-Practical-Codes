;To write an assembly language program to multiply two 8-bit numbers using 8085.
MVI D, 00H       ; Clear register D to store high byte of the result
MVI A, 05H       ; Load first 8-bit number into accumulator (e.g., 05H)
MVI B, 04H       ; Load second 8-bit number into register B (e.g., 04H)
LOOP: ADD A      ; Add accumulator to itself
DCR B            ; Decrement register B
JNZ LOOP         ; If B ≠ 0, repeat loop
MOV L, A         ; Store the low byte of the result in L
MOV H, D         ; Store the high byte of the result in H
HLT              ; Halt the program
