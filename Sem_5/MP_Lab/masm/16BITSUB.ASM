assume cs:code,ds:data
data segment 
	opr1 dw 9999h
        	opr2 dw 7777h
       	result dw 0000H
	carry dw 0000H      
data ends
code segment
        	org 0100h
start: 	mov ax,data
        	mov ds,ax
        	mov ax,opr1
        	mov bx,opr2
	mov cx,0000h
	sub ax,bx
	jnc here
        	neg ax
	inc cx
here:  	mov result,ax
	mov carry,cx
        	mov ah,4ch
       	 int 21h
	code ends
end start
