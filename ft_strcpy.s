; char 	*ft_strcpy(char *dest, const char *src)
            section .text

            global ft_strcpy
ft_strcpy:
    mov     rcx , 0                 ; iniciar o contador

cpy:
    cmp     BYTE [rsi + rcx], 0    ; verificar se o char for nulo
    je      end                      ; se for nulo vai para ' end '
    mov     dl , BYTE [rsi + rcx]   ; trocar o caractere dl que e 1 byte ...
    mov     BYTE [rdi + rcx], dl    ; receber os argumentos para copiar
    inc     rcx                     ; i++
    jmp     cpy                     ; repetir o ciclo pra copiar

end:
    mov     BYTE [rdi + rcx], 0     ; '\0'
    mov     rax, rdi                ; retorno o valor em 'rax' da string copiada rdi
    ret