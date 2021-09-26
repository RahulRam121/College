	MOV A, R0	; ASCII equivalent of first digit.
	ANL A, #0F0H
	SWAP A
	ADD A, #30H
	MOV R1, A
	MOV A, R0	; ASCII equivalent of second digit.
	ANL A, #0FH
	ADD A, #30H
	MOV R2, A
HERE: 	SJMP HERE
