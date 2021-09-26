assume cs:code,ds:data
data segment 
	array db 06h, 05h, 09h, 02h, 07h, 03h, 01h, 08h, 04h
	pos db 00H
data ends
code segment
        	org 0100h
start:  	mov ax,data
	mov ds, ax
        	mov cl, 09H
	mov bl, 01H
	mov dl, 01H
	mov si, offset array
	mov al, [si]
L1:	inc si
	inc dl
	cmp al, [si]
	jae skip
	mov al, [si]
	mov bl, dl
skip:	LOOP L1
	mov pos, bl
	mov ah, 02H
	mov dl, bl
	add dl, 30h
	int 21h
        	mov ah,4ch
        	int 21h
code ends
end start
