section .data
    msg db "Hello World", 0xA
    len equ $ - msg

section .text
    global _start

_start:
    call .loop

.loop:
    cmp r9, 10
    je .exit
    ; sys_write
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, len
    syscall
    inc r9
    jmp .loop

.exit:
    mov rax, 60
    xor rdi, rdi
    syscall
