
;Program for Subtracting 2, 8 bit BCD numbers

assume cs:code,ds:data
data segment 
	opr1 db 56h
	opr2 db 68h
	result db 00H
	carry db 00H      
data ends
code segment
	org 0100h
start: 	mov ax, data
	mov ds, ax
	mov al, opr1
	mov bl, opr2
	mov cl, 00h
	sub al, bl
	das 
	jnc here
	mov bl, al
	mov al, 99h
	sub al, bl
	inc al
	das
	inc cl
here:  	mov result, al
	mov carry, cl
	mov ah, 4ch
	int 21h
code ends
end start
