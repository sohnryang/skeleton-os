org 0x7c00
bits 16
global loader

	xor ax, ax
	mov ds, ax
	mov es, ax
	mov ss, ax
	mov sp, 0x7c00

loader:
	mov al, 0x00		; page should be 0
	mov ah, 0x05		; set active page to 0
	int 0x10

	call get_cursor_pos

	mov cx, [ldmsg_len]
	mov bp, ldmsg
	mov bl, 0x0f		; color - white
	call print_str

	mov ah, 0x00		; reset disk system
	mov dl, 0x80		; drive is hard disk drive
	int 0x13

	mov ax, 0x500
	mov es, ax
	mov bx, 0		; load kernel to 0x500:0000

	mov ah, 0x02		; read sectors into memory
	mov al, 0x01		; read one sector
	mov ch, 0x00		; cylinder 0
	mov cl, 0x01		; sector 1
	mov dh, 0x00		; head 0
	mov dl, 0x80		; drive is hard disk drive
	int 0x13

	jmp 0x500:0000

	hlt

get_cursor_pos:
	mov ah, 0x03		; tell 0x10 interrupt to get cursor position
	mov bh, 0x00		; page 0
	int 0x10
	ret

print_str:
	mov al, 0x01		; write mode
	mov ah, 0x13		; tell 0x10 interrupt to write string
	mov bh, 0x00		; page 0
	int 0x10
	ret

ldmsg db 'Loading OS... '
ldmsg_len dw $ - ldmsg
donemsg db 'done',0x0d,0x0a
donemsg_len dw $ - donemsg
failmsg db 'fail',0x0d,0x0a
failmsg_len dw $ - failmsg

	times  510 - ($-$$) db 0
	dw 0xaa55
