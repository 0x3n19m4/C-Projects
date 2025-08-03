section .data

section .text
    global _start

_start:
    mov rdi, 5
    mov rsi, 5

    call sum
    add rax, 10

    mov rdi, rax
    mov rax, 60
    syscall

sum:
    mov rax, rdi
    add rax, rsi
    ret    