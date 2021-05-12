;size_t        ft_read(int fd, char *buf, size_t count)
                section .text   
                global ft_write
                extern __errno_location
ft_write:
    mov rax, 1                      ; apenas para iniciação
    syscall                         ; chamada da funçao
    cmp		rax, 0			    	; verificaçao de error
	jmp		error			        ; se o valor de retorno de rax for negativo = erro
	ret						        
error:
	neg		rax			       	    ; rax = -rax (codigos sao positivos)
	mov		rdi, rax			    ; rdi = rax (salva o valor de rax em rcx)
	call	__errno_location wrt ..plt   ; chama a funcao que retorna o valor ou erro
	mov		[rax], rdi		    	; coloca o valor em error
	mov		rax, -1			    	; retorna -1 e nao retorna o valor de errno
	ret