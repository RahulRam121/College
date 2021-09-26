     
;Program for BCD to Hexadecimal

assume cs:code,ds:data
data segment
    BCD db 12h
    HEX db 00h
data ends
code segment
    org 0100h
start:  
    mov ax, data
    mov ds, ax
    mov al, BCD
    mov bl, BCD
    and bl, 0Fh
    and al, 0F0h
    mov cl, 04
    ror al, cl
    mov dl, 0Ah
    mul dl
    add al, bl
    mov HEX, al
    mov ah,4ch
    int 21h
code ends
end start
