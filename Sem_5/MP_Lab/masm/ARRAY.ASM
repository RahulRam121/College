; Program for array manipulation using 8086 assembly language

assume cs:code, ds:data

data segment
	a db 22h,23h,24h,25h
	len dw $-a
	result db 00h
data ends

code segment
	org 0100h
start:	mov ax, data
	mov ds, ax
	lea si, a
	mov ax, 0
	mov cx, len
	mov di,3000
here:	mov al, a[si]
	mov [di], al
	inc di
	inc si
	loop here
	dec di
	mov al,[di]
	mov result, al
	mov ah, 4ch
	int 21h
code ends
end start
	