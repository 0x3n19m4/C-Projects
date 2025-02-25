section .data
    	text1 db "Greater", 0xA
	len1 equ $ - text1 

    	text2 db "Smaller", 0xA
	len2 equ $ - text2

section .text
    	global _start

_start:
    	push rbp
    	mov rbp, rsp
    	sub rsp, 16

    	mov qword [rbp - 8], 50
    	mov qword [rbp - 16], 30

    	mov rax, qword [rbp - 8] 
    	mov rbx, qword [rbp - 16]
    
    	cmp rax, rbx
    	jg _greater

	mov rsp, rsp
	pop rbp

    	jmp _smaller

_greater:
    	mov rax, 1
    	mov rdi, 1
    	mov rsi, text1
    	mov rdx, len1
    	syscall
	jmp _exit

_smaller:
    	mov rax, 1
    	mov rdi, 1
    	mov rsi, text2
    	mov rdx, len2
	syscall
	jmp _exit

_exit:
	mov rax, 60
	xor rdi, rdi
	syscall
