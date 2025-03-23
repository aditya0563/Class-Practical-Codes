;To write an assembly language program to find the larger of two numbers using 8085.
MVI A, 25H       ; Load 25H into accumulator (first number)
MVI B, 15H       ; Load 15H into register B (second number)
CMP B            ; Compare A with B
JC SMALLER       ; Jump if A < B
MOV C, A         ; Move larger number (A) to register C
JMP END          ; Jump to the end
SMALLER: MOV C, B; Move larger number (B) to register C
END: HLT         ; Halt the program
