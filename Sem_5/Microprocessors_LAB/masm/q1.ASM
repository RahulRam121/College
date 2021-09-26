assume cs:code,ds:data
data segment
	day db 01 dup(?)
	month db 01 dup(?)
	year db 02 dup(?)
	hour db 01 dup(?)
	minute db 01 dup(?)
	second db 01 dup(?)
data ends
code segment
    	org 0100h
start:	mov ax,data
 	mov ds,ax

	; AH = 2A with INT 21 will give system date
	mov ah,2ah
 	int 21H
	mov si, offset day
	mov [si], dl	; DL = day
	mov si, offset month
	mov [si], dh	; DH = month
	mov si,offset year
 	mov [si],cx	; CX = year

	; AH = 2C with INT 21 will give system time
	mov ah, 2ch
	int 21h
	mov si,offset hour
 	mov [si],ch	; CH = hour
	mov si,offset minute
 	mov [si],cl	; Cl = minute
	mov si,offset second	
 	mov [si],dh	; DH = second
	; Ah = 4c with INT 21 - terminates the program.
	mov ah,4ch
	int 21h
code ends
end start