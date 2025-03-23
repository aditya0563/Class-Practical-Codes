;o write an assembly language program to add two 16-bit numbers using 8086.
MOV AX, 2505H    ; Load first 16-bit number into AX
MOV BX, 1503H    ; Load second 16-bit number into BX
ADD AX, BX       ; Add BX to AX
HLT              ; Halt the program
