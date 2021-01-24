org 0x7c00
bits 16
global loader

	xor ax, ax
	mov ds, ax
	mov es, ax

loader:
	mov al, 0x00	; page should be 0
	mov ah, 0x05	; set active page to 0
	int 0x10

	mov ah, 0x03	; tell 0x10 interrupt to get cursor position
	mov bh, 0x00	; page 0
	int 0x10

	mov al, 0x01	; write mode
	mov ah, 0x13	; tell 0x10 interrupt to write string
	mov bl, 0x04	; color - red
	mov bh, 0x00	; page 0
	mov cx, [len]	; message length
	mov bp, msg	; message address
	int 0x10

	hlt

msg db 'Hell world'
len dw $ - msg

	times  510 - ($-$$) db 0
	dw 0xaa55
