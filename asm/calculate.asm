section .bss
        op resb 1
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
        call _ask_and_choose
        call _ask_and_inpt_fst_num
        call _ask_and_inpt_scnd_num
        call _compare_and_jump

_compare_and_jump:
        mov rsi, num1
        call atoi
        mov rbx, rax

        mov rsi, num2
        call atoi
        mov rcx, rax

        mov al, [op]

        cmp al, '+'
        je _sum

        cmp al, '-'
        je _sub

        cmp al, '*'
        je _mul

        cmp al, '/'
        je _div
        ret


_ask_and_choose:
        mov rax, 1
        mov rdi, 1
        mov rsi, action
        mov rdx, action_len
        syscall

        mov rax, 0
        mov rdi, 0
        mov rsi, op
        mov rdx, 1
        syscall
        ret

_ask_and_inpt_fst_num:
        mov rax, 1
        mov rdi, 1
        mov rsi, fst_num
        mov rdx, fst_num_len
        syscall

        mov rax, 0
        mov rdi, 0
        mov rsi, num1
        mov rdx, 16
        syscall
        ret

_ask_and_inpt_scnd_num:
        mov rax, 1
        mov rdi, 1
        mov rsi, fst_num
        mov rdx, fst_num_len
        syscall

        mov rax, 0
        mov rdi, 0
        mov rsi, num2
        mov rdx, 16
        syscall
        ret

_sum:
        mov rbx, [num1]
        mov rcx, [num2]
        add rbx, rcx
        ret

_sub:
        mov rax, [num1]
        mov rbx, [num2]
        sub rax, rbx
        ret

_exit:
        mov rax, 60
        xor rdi, rdi
        syscall
