; program for HEX to BCD conversion
mov r0, #00h
MOV A, r1
MOV B, #064h
DIV AB
MOV r2, A
MOV A, B
MOV B, #0Ah
DIV AB
SWAP A
ORL B,A
MOV r3, B
HERE : SJMP HERE