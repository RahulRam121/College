DATA SEGMENT
	num db 05H
	result dw 00H
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START: 	MOV AX,DATA
	MOV DS,AX
	mov ax, 0000H
	mov cl, num
	mov ch, 00H
l:	add ax, cx
	loop l
	mov result, ax
	MOV Ah,4CH
	INT 21H
CODE ENDS
END START