;To write an assembly language program to add two nibbles using 8051.
MOV A, #0FH      ; Load the first nibble (lower 4 bits)
MOV B, #0AH      ; Load the second nibble
ADD A, B         ; Add the two nibbles
HLT              ; Halt the program
