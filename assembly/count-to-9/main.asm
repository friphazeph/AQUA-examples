
; This program counts up to 9 starting from 0
; and when it reached 9, it exits

section .text
	main:
		push rbp
		mov  rbp rsp
		sub      rsp 16
		
		mov [rbp-8] 0
		jmp condition
		
		increment:
			mov rdi format
			mov rsi [rbp-8] ; rdi and rsi are the first and second argument registers respectively
			
			call print
			inc [rbp-8]
		
		condition:
			cmp [rbp-8] 9
			jle increment
		
		mov rax 0xBEEF ; return value
		leave
		ret

section .data
	format: ; i %lld\n
		db 69H 20H 25H 6CH 6CH 64H 0AH 00H
		db 00H 00H 00H 00H 00H 00H 00H 00H
		db 00H 00H 00H 00H 00H 00H
