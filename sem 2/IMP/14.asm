;To write an assembly language program to generate a square wave of 5 KHz using timer 0 in mode 0.
MOV TMOD, #01H   ; Set Timer 0 in Mode 1 (16-bit timer mode)
MOV TH0, #0FCH   ; Load high byte of count for 5 KHz square wave
MOV TL0, #18H    ; Load low byte of count for 5 KHz square wave
SETB TR0         ; Start Timer 0
HERE: JNB TF0, HERE ; Wait for Timer 0 to overflow
CLR TF0          ; Clear Timer 0 overflow flag
CPL P1.0         ; Toggle the output pin to generate square wave
SJMP HERE        ; Repeat indefinitely
