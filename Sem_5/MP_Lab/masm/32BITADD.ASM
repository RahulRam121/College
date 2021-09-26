
;Program for adding 2, 8 bit numbers

assume cs:code,ds:data
data segment 
	opr1 dd 11345678h
        	opr2 dd 0F3235456h
        	result dd 00000000H
	carry db 00H      
data ends
code segment
        	org 0100h
start:  	mov ax,data
        	mov ds,ax
        	mov ax, word ptr opr1
        	mov bx, word ptr opr2
	mov ch,00h
	add ax, bx
	mov word ptr result, ax
	mov ax,word ptr  opr1 + 2
	mov bx,word ptr  opr2+2
	adc ax, bx
	jnc here
	inc ch
here:   	mov word ptr result+2, ax
        	mov carry,ch
        	mov ah,4ch
        	int 21h
code ends
end start
