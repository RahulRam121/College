	MOV A, R0 	;input1
	MOV B, R1	;input2
	MUL AB		;BA = A x B
	MOV R2, B
	MOV R3, A
HERE: 	SJMP HERE
