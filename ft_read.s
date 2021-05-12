;size_t        ft_read(int fd, char *buf, size_t count)
                section .text   
                global ft_read
extern __errno_location
extern error

ft_read:                          ; fd = rdi | rsi = *buf | rdx = count
        push    rbx
        mov     rax, 0            ; if (rax < 0)
        syscall    
        test   rax, rax           ; verificar se rax e negativo
        js      read_error        ; se for error, vai para funçao  
        pop     rbx
        ret                       ; return (rax)
read_error:
        mov     rbx, rax          ; rbx = rax
        neg     rbx               ; rbx = -rbx
        call	__errno_location wrt ..plt
        mov     [rax], rbx        ; mostra error no retorna da funçao
        mov     rax, -1           ; rax = -1  
        pop     rbx                 
        ret