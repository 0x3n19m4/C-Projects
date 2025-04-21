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
        mov ebx, 1	; stdout descriptor  
        mov ecx, text1  ; text1 output                
        mov edx, 19	; lenght of text1   
        int 0x80        ; 32-bit syscall         
        ret                             
                                        
_GetName:                               
        ; input                         
        mov eax, 3      ; syscall sys_read                
        mov ebx, 0      ; stdin descriptor                
        mov ecx, name                   
        mov edx, 16                     
        int 0x80                         
        ret                             
                                        
_HelloPrnt:                             
        mov eax, 3                      
        mov ebx, 1                      
        mov ecx, text2                  
        mov edx, 7                      
        int 0x80                         
        ret                             
                                        
_NamePrnt:                              
        mov eax, 3                      
        mov ebx, 1                      
        mov ecx, name                   
        mov rdx, 16                     
        int 0x80                         
        ret 
