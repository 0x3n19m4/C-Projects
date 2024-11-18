global _start

section .data
message: db "Hello World!", 0x0a
len equ $ - message

section .text
_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, message
    mov rdx, len
    syscall

    mov rax, 60
    syscall