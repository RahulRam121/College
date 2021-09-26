;Program for sorting array using bubble sort in descending order.

assume cs:code,ds:data
data segment
    len db 05h
    array db 06h, 05h, 07h, 02h, 09h

data ends
code segment
    org 0100h
start:  
    mov ax, data
    mov ds, ax
    
    mov cl, len
    dec cl
l1:
    mov ch, len
    dec ch
    mov si, offset array
l2:
    mov al, [si]
    inc si
    cmp al, [si]
    jae here
    xchg al, [si]
    dec si
    xchg al, [si]
    inc si
here:
    dec ch
    jnz l2
    dec cl
    jnz l1
    mov ah,4ch
    int 21h
code ends
end start
