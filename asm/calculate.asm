section .bss
        action_inpt resb 1
        num1 resb 16
        num2 resb 16

section .data
        action db "Choosee an action[ + - * / ]: ", 0xA
        fst_num db "Enter first number: ", 0xA
        scnd_num db "Enter second number: ", 0xA

        action_len equ $ - action
        fst_num_len equ $ - fst_num
        scnd_num_len equ $ - scnd_num

section .text
        global _start

_start:
        call _ask
        call _choose
        call _ask_fst_num
        call _inpt_fst_num


_ask:
        mov rax, 1
        mov rdi, 1
        mov rsi, action
        mov rdx, action_len
        syscall
        ret

_choose:
        mov rax, 0
        mov rdi, 0
        mov rsi, action_inpt
        mov rdx, 1
        syscall
        ret

_ask_fst_num:
        mov rax, 1
        mov rdi, 1
        mov rsi, fst_num
        mov rdx, fst_num_len
        syscall
        ret

_inpt_fst_num:
        mov rax, 0
        mov rdi, 0
        mov rsi, num1
        mov rdx, 16
        syscall
        ret

_ask_scnd_num:
        mov rax, 1
        mov rdi, 1
        mov rsi, fst_num
        mov rdx, fst_num_len
        syscall
        ret

_inpt_scnd_num:
        mov rax, 0
        mov rdi, 0
        mov rsi, num2
        mov rdx, 16
        syscall
        ret

_summation:
        mov rbx, [num1]
        mov rcx, [num2]
        add rbx, rcx
        syscall
        jmp _exit

_exit:
        mov rax, 60
        xor rdi, rdi
        syscall