section .data
        cybers3c:db 100,32                     ;db = 1 byte
        s3c:db 30,32
        
        msg1        db 'cybers3c = 100'        ;print
        Val1        equ $ - msg1               
        msg2        db 10,'s3c = 30',0        ;print
        Val2        equ $ - msg2

section .bss
        num1 resb 5             ; resb server para alogar byte ( resb = 1 byte) 
        num2 resb 5

section .text
        global _start 

_start:
        mov eax, [cybers3c]
        mov ecx, msg1 
        mov edx, Val1
        call mst_saida
        mov ecx, num1
        mov edx, 10
        mov eax, 3
        mov ebx, 0
        int 80h

        mov ebx, eax

        mov eax, [s3c]
        mov ecx, msg2
        mov edx, Val2
        call mst_saida
        mov ecx, num2
        mov edx, 10
        mov eax, 3
        mov ebx, 0
        int 80h

        mov eax, 1
        mov ebx, 0
        int 0x80

mst_saida:
        mov rax, 4
        mov rbx, 1
        int 80h
        ret