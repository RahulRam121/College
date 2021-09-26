
;Program for Multiplying 2, 8 bit numbers

assume cs:code,ds:data
data segment 
	opr1 db 03h
      	opr2 db 02h
       	hres db 00H
       	lres db 00H
data ends
code segment
       	org 0300h
start:  mov ax,data
       	mov ds,ax
	mov al,opr1
       	mov bl,opr2
	mul bl
	mov hres,ah
       	mov lres,al
       	mov ah,4ch
       	int 21h
code ends
end start
