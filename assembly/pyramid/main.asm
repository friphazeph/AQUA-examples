
; This program creates an ampersand pyramid 15 characters tall
; with a dollar sign every odd line and every even column

section .text
	main:
		push rbp
		mov  rbp rsp
		sub      rsp 16
		
		mov [rbp-0x8] 0
		jmp main_for_loop_condition
		
		main_for_loop:
			mov [rbp-0x10] 0
			jmp line_for_loop_condition
			
			line_for_loop:
				mov  rsi [rbp-0x8]
				mul  rsi [rbp-0x10]
				and  rsi 0b1
				
				test rsi rsi
				jz   print_dollar_char
				
				mov rsi 24H
				jmp print_char
				
				print_dollar_char:
					mov rsi 26H
				
				print_char:
					mov rdi char
					call print
					inc [rbp-0x10]
			
			line_for_loop_condition:
				mov rax [rbp-0x10]
				cmp rax [rbp-0x8]
				jlt line_for_loop
			
			mov rdi new_line
			call print
			inc [rbp-0x8]
		
		main_for_loop_condition:
			cmp [rbp-0x8] 15
			jle main_for_loop
		
		mov rax 0xBEEF ; return value
		leave
		ret

section .data
	new_line: ; \n
		db 0AH 00H
	
	char:     ; %c 
		db 25H 63H 20H 00H
