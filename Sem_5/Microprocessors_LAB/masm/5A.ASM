;Program for matrix addition

assume cs:code,ds:data
data segment
    row1 db 02h
    row2 db 02h
    column1 db 03h
    column2 db 03h
    mat1 db 0ffh, 02h, 03h
               db 04h, 05h, 06h
    mat2 db 0eeh, 30h, 03h
               db 03h, 03h, 03h
    result dw 00h, 00h, 00h
              dw 00h, 00h, 00h

data ends
code segment
    org 0100h
start:  
    mov ax, data
    mov ds, ax
    
    mov al, row1
    mov bl, row2    
    cmp al, bl
    jnz exit
    mov al, column1
    mov bl, column2
    cmp al, bl
    jnz exit
    
    mov al, row1
    mul bl
    mov ah, 00h
    mov cx, ax
    lea si, mat1
    lea di, mat2
    lea bx, result
l1:
    mov ah, 00h
    mov al, [si]
    mov dl, [di]
    add al, dl
    jnc here
    inc ah
here:
   mov [bx], ax
   inc si
   inc di
   add bx, 2
   loop l1
exit:
    mov ah,4ch
    int 21h
code ends
end start
