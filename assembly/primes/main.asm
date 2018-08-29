
; This program goes through 4096 even numbers,
; testing if they are prime, and if not,
; print out what their smallest divider (not 1) possible

section .text
	main:
		push rbp
		mov  rbp rsp
		sub      rsp 16
		
		mov     [rbp-0x28] 4096 ; the amount of numbers to be tested
		mov rax [rbp-0x28]
		mov rsi rax
		
		mov rdi searching_primes
		call print
		
		mov [rbp-0x8] 1
		
		mov rdi two_is_prime
		call print
		
		mov [rbp-0x10] 0
		jmp main_for_loop_condition
		
		main_for_loop:
			add [rbp-0x8]  2
			mov [rbp-0x18] 1
			mov [rbp-0x20] 3
			jmp division_test_loop_condition
			
			division_test_loop:
				mov rax [rbp-0x8]
				div     [rbp-0x20]
				
				mov  rax rdx
				test rax rax
				jnz  increment_test
				
				mov rdx [rbp-0x20]
				mov rsi [rbp-0x8]
				
				mov  rdi a_can_be_div_by_b
				call print
				
				mov [rbp-0x18] 0
				jmp prime_confirmed
				
			increment_test:
				inc [rbp-0x20]
				
			division_test_loop_condition:
				mov rax [rbp-0x8]
				mov rdx rax
				
				shr rdx 63
				add rax rdx
				sar rax 1
				
				cmp [rbp-0x20] rax
				jlt division_test_loop
			
			prime_confirmed:
				cmp [rbp-0x18] 0
				jz  increment_main
				
				mov  rsi [rbp-0x8]
				mov  rdi a_is_prime
				call print
		
		increment_main:
			inc [rbp-0x10]
		
		main_for_loop_condition:
			mov rax [rbp-0x10]
			cmp rax [rbp-0x28]
			jlt main_for_loop
		
		mov  rdi new_line
		call print
		
		mov rax 0xBEEF ; return value
		leave
		ret

section .data
	new_line:          ; \n
		db 0AH 00H
	
	searching_primes:  ; Searching for %lld prime numbers ...\n
		db 53H 65H 61H 72H 63H 68H 69H 6EH
		db 67H 20H 66H 6FH 72H 20H 25H 6CH
		db 6CH 64H 20H 70H 72H 69H 6DH 65H
		db 20H 6EH 75H 6DH 62H 65H 72H 73H
		db 20H 2EH 2EH 2EH 0AH 00H
	
	two_is_prime:      ; 2 is prime\n
		db 32H 20H 69H 73H 20H 70H 72H 69H
		db 6DH 65H 0AH 00H
	
	a_can_be_div_by_b: ; %lld can be divided by %lld\n
		db 25H 6CH 6CH 64H 20H 63H 61H 6EH
		db 20H 62H 65H 20H 64H 69H 76H 69H
		db 64H 65H 64H 20H 62H 79H 20H 25H
		db 6CH 6CH 64H 0AH 00H
	
	a_is_prime:        ; %lld is prime
		db 25H 6CH 6CH 64H 20H 69H 73H 20H
		db 70H 72H 69H 6DH 65H 0AH 00H
