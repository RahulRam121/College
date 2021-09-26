;Program for adding 2, 8-bit BCD numbers

assume cs:code,ds:data
data segment 
	opr1 db 67h
	opr2 db 95h
	result db 00H
	carry db 00H      
data ends
code segment
	org 0100h
start:	mov ax,data
	mov ds,ax
	mov al,opr1
	mov bl,opr2
	mov cl, 00h
	add al, bl
	daa
	jnc here
	inc cl
here:	mov result, al
	mov carry ,cl
	mov ah, 4ch
	int 21h
code ends
end start
