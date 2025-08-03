section .data

section .text
    global _start

_start:
    mov rdi, 5   ; firch argument
    mov rsi, 5   ; second argument

    call sum
    add rax, 10   ; <---------------------------------------------------------------| add 10 to rax(10) = 20
                  ;                                                                 |
    mov rdi, rax  ;                                                                 |
    mov rax, 60   ;                                                                 |
    syscall       ;                                                                 |
                  ;                                                                 |
sum:              ;                                                                 |
    mov rax, rdi  ;                                                                 |
    add rax, rsi  ;                                                                 |
    ret           ; ret instruction will return result from add operation to rax register 