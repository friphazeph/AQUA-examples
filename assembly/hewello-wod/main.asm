
; This program simply prints out "hewello wod!"
; by replacing the first character in the "Hello world!" string with a "w",
; then overlaying the 8 first bytes of this new string
; on the other with 2 bytes offset to the right

section .text
	main:
		push rbp
		mov  rbp rsp
		sub      rsp 16
		
		mov rdi string
		mov rax [rdi]
		
		and rax 0xFFFFFFFFFFFFFF00
		add rax 0x77
		
		mov [rdi+1*2] rax ; note this unnecessarily complex address calculation
		call print
		
		mov rax 0xBEEF ; return value
		leave
		ret

section .data
	string: ; Hello world!
		db 48H 65H 6CH 6CH 6FH 20H 77H 6FH
		db 72H 6CH 64H 21H 0AH 00H 00H 00H
		db 00H 00H 00H 00H 00H 00H
