assume cs:code,ds:data
data segment
    count dw 0005h
    str1 db "hello",0
    str2 db "world",0
data ends
code segment
    org 0100h
start:
    mov ax,data
    mov ds,ax
    mov cx,count
    mov si, offset str1
    mov di, offset str2
l1:
    mov al, [si]
    mov [di], al
    inc si
    inc di
    loop l1
    mov ah,4ch
    int 21h
code ends
end start