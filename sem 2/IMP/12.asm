;Write an assembly language program to interface the 8255 with 8086. Read the status of switches connected at the input and display the status at output LEDs and the display of the trainer kit.
MOV AL, 80H      ; Control word to configure 8255 ports
OUT CONTROL, AL  ; Output control word to 8255 control port
IN AL, PORTA     ; Read the status of switches from Port A
OUT PORTB, AL    ; Display the status on LEDs connected to Port B
HLT              ; Halt the program
