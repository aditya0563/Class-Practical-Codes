;To write an assembly language program to generate the factorial of an 8-bit number using 8086.
MOV CX, 05H      ; Load the number for which the factorial is to be calculated (e.g., 5)
MOV AX, 01H      ; Initialize the result in AX
FACTORIAL: MUL CX; Multiply AX by CX
DEC CX           ; Decrement CX by 1
JNZ FACTORIAL    ; Repeat until CX becomes 0
HLT              ; Halt the program
