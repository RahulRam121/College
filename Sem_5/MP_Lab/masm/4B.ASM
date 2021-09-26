     
;Program for Hexadecimal to BCD

assume cs:code,ds:data
data segment
    HEX db 0FFh
    BCD1 db 00h
    BCD0 db 00h
data ends
code segment
    org 0100h
start:  
    mov ax, data
    mov ds, ax
    mov ah, 00h  
    mov al, HEX
    mov bl, 64h
    div bl
    mov BCD1, al
    mov al, ah
    mov ah, 00h
    mov bl, 0Ah
    div bl
    mov cl, 04h
    ror al, cl
    mov bl, ah
    add al, bl
    mov BCD0, al
    mov ah,4ch
    int 21h
code ends
end start
