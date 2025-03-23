;Write an assembly language program to add and subtract two 8-bit numbers using 8085.
MVI A, 25H       ; Load 25H into accumulator
MVI B, 15H       ; Load 15H into register B
ADD B            ; Add content of B to accumulator
MOV C, A         ; Move result to register C
MVI A, 25H       ; Load 25H into accumulator again
SUB B            ; Subtract content of B from accumulator
MOV D, A         ; Move result to register D
HLT              ; Halt the program
