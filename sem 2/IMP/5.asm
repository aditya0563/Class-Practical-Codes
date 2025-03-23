;To write an assembly language program to find the smallest number from the series of ten numbers using 8085.
LXI H, 0500H     ; Load the starting address of the series into HL
MOV A, M         ; Load the first number into accumulator
INX H            ; Point to the next number
MOV B, A         ; Store the first number in register B for comparison
LOOP: CMP M      ; Compare A (current smallest) with M (next number)
JC NEXT          ; Jump if the next number is smaller
MOV B, M         ; Update register B with the new smallest number
NEXT: INX H      ; Move to the next memory location
DCR C            ; Decrement counter (series of 10)
JNZ LOOP         ; Repeat until all numbers are checked
HLT              ; Halt the program
