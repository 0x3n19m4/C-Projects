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
                                        
        mov eax, 1	; syscall sys_exit
	xor ebx, ebx                     
        int 0x80        ; 32-bit syscall         
                                        
_Qstn:                                  
        mov eax, 4	; syscall sys_write                      
        mov edi, 1	; stdout descriptor  
        mov esi, text1  ; text1 output                
        mov edx, 19	; lenght text1   
        int 0x80        ; 32-bit syscall         
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
        ret 
