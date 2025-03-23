;To write an assembly language program to generate a square wave of 1 KHz frequency using 8086.
MOV AL, 0FFH     ; Load AL with FFH (to toggle output)
OUT PORT, AL     ; Output the value to the port
CALL DELAY       ; Call delay subroutine for half-period of 1 KHz
NOT AL           ; Toggle AL (from FFH to 00H or vice versa)
OUT PORT, AL     ; Output the toggled value to the port
CALL DELAY       ; Call delay subroutine again
JMP $            ; Repeat forever
DELAY: ; Subroutine to generate a delay
MOV CX, 0FFFFH   ; Load CX with delay value
LOOP: DEC CX     ; Decrement CX
JNZ LOOP         ; Repeat until CX = 0
RET              ; Return from subroutine
