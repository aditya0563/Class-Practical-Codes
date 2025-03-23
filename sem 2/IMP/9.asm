;A data string of ten bytes is located from the starting address 0500. Write an assembly language program to convert the data string to its equivalent 2's complement form and store the result at 0600 onward locations.
LEA SI, 0500H    ; Load starting address of the data string into SI
LEA DI, 0600H    ; Load starting address of the destination into DI
MOV CX, 0AH      ; Load the count (10 bytes) into CX
LOOP: MOV AL, [SI] ; Load the byte from memory into AL
NOT AL           ; Take 1's complement
ADD AL, 01H      ; Add 1 to get 2's complement
MOV [DI], AL     ; Store the result at the destination
INC SI           ; Increment source index
INC DI           ; Increment destination index
LOOP LOOP        ; Decrement CX and repeat if CX ≠ 0
HLT              ; Halt the program
