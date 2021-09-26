; counting number of zeros and ones in a 16-bit number
assume cs:code, ds:data
data segment 
	num dw 0abcdh	
	zeros db 00h
	ones db 00h
data ends

code segment
	org 0100h
start:	mov ax, data
	mov ds, ax
	mov bx, 0000h
	mov ax, num
	mov cx, 0010h
l1:	rcr ax, 1
	jc one
	inc bl
	jmp here
one:	inc bh
here:	loop l1
	mov ones, bh
	mov zeros, bl
	mov ah, 4ch
	int 21h 
code ends
end start