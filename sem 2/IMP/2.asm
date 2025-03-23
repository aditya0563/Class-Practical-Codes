;To write an assembly language program to add and subtract two 16-bit numbers using 8085.
LXI H, 2505H     ; Load 2505H into register pair HL
LXI D, 1503H     ; Load 1503H into register pair DE
MOV A, L         ; Move lower byte of HL to accumulator
ADD E            ; Add lower byte of DE to accumulator
MOV L, A         ; Store the result in L
MOV A, H         ; Move higher byte of HL to accumulator
ADC D            ; Add higher byte of DE with carry
MOV H, A         ; Store the result in H
MOV A, L         ; Load lower byte of the result for subtraction
SUB E            ; Subtract lower byte of DE
MOV L, A         ; Store the result in L
MOV A, H         ; Load higher byte of the result
SBB D            ; Subtract higher byte of DE with borrow
MOV H, A         ; Store the result in H
HLT              ; Halt the program
