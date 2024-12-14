section .bss                            
        name resb 16                    
                                        
section .data                           
        text1 db "What is your name? "  
        text2 db "Hello, "              
                                        
section .text                           
        global _start                   
                                        
_start:                                 
        call _Qstn                      
        call _GetName                   
        call _HelloPrnt                 
        call _NamePrnt                  
                                        
        mov rax, 60                     
        syscall                         
                                        
_Qstn:                                  
        mov rax, 1                      
        mov rdi, 1                      
        mov rsi, text1                  
        mov rdx, 19                     
        syscall                         
        ret                             
                                        
_GetName:                               
        ; input                         
        mov rax, 0                      
        mov rdi, 0                      
        mov rsi, name                   
        mov rdx, 16                     
        syscall                         
        ret                             
                                        
_HelloPrnt:                             
        mov rax, 1                      
        mov rdi, 1                      
        mov rsi, text2                  
        mov rdx, 7                      
        syscall                         
        ret                             
                                        
_NamePrnt:                              
        mov rax, 1                      
        mov rdi, 1                      
        mov rsi, name                   
        mov rdx, 16                     
        syscall                         
<<<<<<< HEAD
        ret                             
=======
        ret                             
>>>>>>> b12d1f4 (Update test.asm)
