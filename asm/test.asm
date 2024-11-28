section .bss
        buffer resb 128

section .data
        prompt db "What's your name? ", 0x0a
        hello db "Hello ", 0x0a
        newline db 10, 0x0a
        len_prompt equ $ - prompt
        len_hello equ $ - hello

section .text
        global _start

_start:
        ; first out
        mov rax, 1
        mov rdi, 1
        mov rsi, prompt
        mov rdx, len_prompt
        syscall

        ; input
        mov rax, 0
        mov rdi, 0
        mov rsi, buffer
        mov rdx, 128
        syscall

        mov rbx, buffer
find_newline:
        cmp byte [rbx], 10
        je newline_found
        cmp byte [rbx], 0
        je newline_found
        inc rbx
        je find_newline

newline_found:
        mov byte [rbx], 0

        ; second out
        mov rax, 1
        mov rdi, 1
        mov rsi, hello
        mov rdx, len_hello
        syscall

        ; third out
        mov rax, 1
        mov rdi, 1
        mov rsi, buffer
        mov rdx, rbx
        syscall

        ; exit
        mov rax, 60
        xor rdi, rdi
        syscall