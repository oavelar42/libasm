section .data
        msg1 db 10,'Aula de assembly',0
        val1 equ $ - msg1


section .bss
        num1 resb 1

section .text   
        global _start

_start:
        mov rax, 1                      ; apenas para iniciação
        mov rcx, msg1
        mov rdx, val1
        call mst_saida			    	; verificaçao de error
        mov ecx, num1
        mov edx, 10
        mov eax, 3
        mov ebx, 0
        int 0x80

mst_saida:
        mov rax, 4
        mov rbx, 1
        int 80h
        ret