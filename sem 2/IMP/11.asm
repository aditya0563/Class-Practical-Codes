;To write an assembly language program to interface a stepper motor with 8086 and rotate the motor in clockwise and anti-clockwise directions.
MOV AL, 88H      ; Load AL with control word for clockwise rotation
OUT PORT, AL     ; Output the control word to the port
CALL DELAY       ; Call delay subroutine
MOV AL, 44H      ; Load AL with control word for anti-clockwise rotation
OUT PORT, AL     ; Output the control word to the port
CALL DELAY       ; Call delay subroutine
JMP $            ; Repeat the process indefinitely
DELAY: ; Subroutine to generate a delay
MOV CX, 0FFFFH   ; Load CX with delay value
LOOP: DEC CX     ; Decrement CX
JNZ LOOP         ; Repeat until CX = 0
RET              ; Return from subroutine
