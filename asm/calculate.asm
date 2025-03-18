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
        call _ask_op
        call _choose_op
        call _ask_fst_num
        call _inpt_fst_num
        call _ask_scnd_num
        call _inpt_scnd_num
        call _compare_and_jump

_compare_and_jump:
        lea rsi, [num1]
        call _atoi
        mov rbx, rax

        lea rsi, [num2]
        call _atoi
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

_ask_op:
        mov rax, 1
        mov rdi, 1
        mov rsi, action
        mov rdx, action_len
        syscall
        ret

_choose_op:
        mov rax, 0
        mov rdi, 0
        mov rsi, op
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
        mov rsi, scnd_num
        mov rdx, scnd_num_len
        syscall
        ret

_inpt_scnd_num:
        mov rax, 0
        mov rdi, 0
        mov rsi, num2
        mov rdx, 16
        syscall
        ret

_atoi:
        xor rax, rax
        xor rcx, rcx
        xor rdx, rdx

        mov rbx, 10

_atoi_loop:
        movzx rcx, byte [rsi]
        cmp rcx, 0x0A
        je _atoi_done
        cmp rcx, 0x30
        jl _atoi_done
        cmp rcx, 0x39
        jg _atoi_done

        sub rcx, 0x30
        imul rax, rbx
        add rax, rcx

        inc rsi
        jmp _atoi_loop

_atoi_done:
        ret

_sum:
        add rbx, rcx
        ret

_sub:
        sub rbx, rcx
        ret

_mul:
        imul rbx, rcx
        ret

_div:
        mov rax, rbx
        xor rdx, rdx
        div rcx
        ret

_exit:
        mov rax, 60
        xor rdi, rdi
        syscall
