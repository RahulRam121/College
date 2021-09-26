	MOV R0, #00
	CLR C
	MOV A, R1 	;input1
	SUBB A, R2 	;input2
	JNC LABEL
	INC R0
	CPL A
	INC A
LABEL: 	MOV R4, A
	MOV 03, R0 	;(mov r3, r0 is invalid)
HERE: 	SJMP HERE
