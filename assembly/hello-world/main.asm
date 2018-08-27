
; This program simply prints out "Hello world!"

section .text
	main:
		push rbp
		mov  rbp rsp
		sub      rsp 16
		
		mov rdi string
		call print
		
		mov rax 0xBEEF ; return value
		leave
		ret

section .data
	string: ; Hello world!
		db 48H 65H 6CH 6CH 6FH 20H 77H 6FH
		db 72H 6CH 64H 21H 0AH 00H 00H 00H
		db 00H 00H 00H 00H 00H 00H
