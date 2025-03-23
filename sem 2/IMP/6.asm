;To write an assembly language program to multiply two 8-bit numbers using the bit rotation method in 8085.
MVI A, 05H       ; Load the multiplicand (e.g., 05H) into accumulator
MVI B, 04H       ; Load the multiplier (e.g., 04H) into register B
MVI C, 00H       ; Clear register C to store the product
LOOP: RAR        ; Rotate accumulator right through carry
JNC NEXT         ; Jump if no carry
ADD B            ; Add multiplicand to accumulator
NEXT: DCR B      ; Decrement the multiplier
JNZ LOOP         ; Repeat until multiplier becomes zero
MOV D, A         ; Store the high byte of the product in register D
HLT              ; Halt the program
