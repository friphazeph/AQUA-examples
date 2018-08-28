
; This program prints out "Hello world! i <number>" in a loop
; where number is a value that increments by one every print
; and that gets set back to zero when it reaches 4

section .text
	main:
		push rbp
		mov  rbp rsp
		sub      rsp 16
		
		mov rdi string
		mov rsi 0
		
		loop: ; loop
			inc  rsi
			mod  rsi 4
			call print
		
		jmp loop
		
		mov rax 0xBEEF ; return value
		leave
		ret

section .data
	string: ; Hello world! %lld
		db 48H 65H 6CH 6CH 6FH 20H 77H 6FH
		db 72H 6CH 64H 21H 20H 69H 20H 25H
		db 6CH 6CH 64H 0AH 00H 00H 00H 00H
		db 00H 00H 00H 00H 00H
