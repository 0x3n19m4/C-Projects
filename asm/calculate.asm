section .data                                         
                                        
section .text                           
        global _start                   
                                        
_start:
    mov rax, 5
    mov rdx, 3
    add rdx, rax

    mov rax, 60
    xor rdi, rdi
    syscall