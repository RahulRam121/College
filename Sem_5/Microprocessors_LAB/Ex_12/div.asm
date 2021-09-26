	MOV A, R0 	; input1
	MOV B, R1	; input2
	DIV AB		; A / B; Quotient in A, Remainder in B
	MOV R3, A
	MOV R2, B
HERE: 	SJMP HERE
