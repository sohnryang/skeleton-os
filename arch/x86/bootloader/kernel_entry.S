org 0x00
bits 16

global kernel_entry

	xor ax, ax
	mov ds, ax
	mov es, ax
	mov ss, ax

	mov ah, 0x0a		; print char
	mov al, '.'		; char to print
	mov bh, 0x00		; page should be 0
	mov cx, 0x08		; print 8 times
	int 0x10
