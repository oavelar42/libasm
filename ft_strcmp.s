; int   ft_strcmp(const char *s1, const char *s2)
        section .text
        
        global ft_strcmp

ft_strcmp:
        push    rcx
        push    rbx
        mov     rcx, rcx              ; i = 0
        mov     rax, rax              ; res = 0
        jmp     loop

loop:
        mov     al, byte [rdi + rcx]    ; al <-s1[i]
        mov     bl, byte [rsi + rcx]    ; bl <- s2[i]
        cmp     al, 0                   ; verifico se al e nulo
        je      end
        cmp     bl, 0                   ; verifico se bl e nulo
        je      end
        cmp     al, bl                  ; se s1[i] != s2[i] vou para end
        jne     end                     ; jne !=
        inc     rcx                     ; i++
        jmp     loop
end:
        movzx   rbx, bl                 ; rbx -> bl == s2
        movzx   rax, al                 ; rax -> vai receber a copia de rbx
        sub     rax, rbx                ; s2(rbx) = s1(rax)
        pop     rbx                     ; recebe o valor , e prepara pra imprimir
        pop     rcx
        ret