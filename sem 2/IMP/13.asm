;To write an assembly language program to find the sum of five bytes stored at any five RAM locations of 8051. Store the lower byte of the result in register A and the higher byte in register R7.
MOV R0, #30H     ; Load starting address of data into R0
MOV R1, #05H     ; Load count of numbers into R1
MOV A, #00H      ; Clear the accumulator
MOV R7, #00H     ; Clear register R7 (higher byte of result)
LOOP: ADD A, @R0 ; Add the value at address pointed by R0 to accumulator
JNC NEXT         ; Jump if no carry
INC R7           ; Increment higher byte (R7) if carry occurs
NEXT: INC R0     ; Increment pointer to next memory location
DEC R1           ; Decrement counter
JNZ LOOP         ; Repeat until all numbers are added
HLT              ; Halt the program
