     
;Program for Division 2, 8 bit numbers

assume cs:code,ds:data
data segment
	opr1 db 88h
        opr2 db 11h
        quotient db 00H
        rem db 00H
data ends
code segment
        org 0400h
start:  mov ax,data
        mov ds,ax
	mov ah,00h
        mov al,opr1
        mov bl,opr2
	div bl
	mov quotient,al
	mov rem,ah
        mov ah,4ch
        int 21h
code ends
end start
