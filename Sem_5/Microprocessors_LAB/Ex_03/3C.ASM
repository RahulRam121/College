assume cs:code,ds:data,es:extra
data segment
    count dw 0005h  
    char db 'x'
    result dw 0000h
data ends
extra segment
    string db "hello",0
extra ends
code segment
    org 0100h
start:
    mov ax,data
    mov ds,ax
    mov ax, extra
    mov es, ax
    mov cx, count
    mov al, char
    inc cx
    mov di, offset string
    cld
    repne scasb 
    je found
    jmp exit
found:
    mov ax, count
    sub ax, cx
    inc ax
    mov result, ax
exit:
    mov ah,4ch
    int 21h
code ends
end start