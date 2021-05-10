section .data
    tit         db 10,'+-------------+',10,'| Calculadora |',10,'+-------------+',0 
    ltit        equ $ - tit
    obVal1      db 10,'Valor 1: ',0
    lobVal1     equ $ - obVal1
    obVal2      db    'Valor 2: ',0
    lobVal2     equ $ - obVal2
    opc1        db 10,'1. Adicionar',0
    lopc1       equ $ - opc1
    opc2        db 10,'2. Subtrair',0
    lopc2       equ $ - opc2
    opc3        db 10,'3. Multiplicar',0
    lopc3       equ $ - opc3
    opc4        db 10,'4. Dividir',0
    lopc4       equ $ - opc4
    msgOpc      db 10,'Deseja Realizar? ',0
    lmsgOpc     equ $ - msgOpc
    msgErro     db 10,'Valor da opção Invalido!',0
    lmsgErro    equ $ - msgErro
    sLinha      db 10,0
    lsLinha      db $ - sLinha

section .bss
    opc         resb 2
    num1        resb 10
    num2        resb 10
    result      resb 10

section .text
    global _start

_start:
    mov rcx, tit
    mov rdx, ltit
    call mst_saida

    mov rcx, obVal1
    mov rdx, lobVal1
    call mst_saida
    mov rcx, num1
    mov rdx, 10
    mov rax, 3
    mov rbx, 0
    int 80h

    mov rcx, obVal2
    mov rdx, lobVal2
    call mst_saida
    mov rcx, num2
    mov rdx, 10
    mov rax, 3
    mov rbx, 0
    int 80h

    mov rcx, opc1
    mov rdx, lopc1
    call mst_saida
    mov rcx, opc2
    mov rdx, lopc2
    call mst_saida
    mov rcx, opc3
    mov rdx, lopc3
    call mst_saida
    mov rcx, opc4
    mov rdx, lopc4
    call mst_saida

    mov rcx, msgOpc
    mov rdx, lmsgOpc
    call mst_saida
    mov rcx, opc
    mov rdx, 2
    mov rax, 3
    mov rbx, 0
    int 80h

    mov ah, [opc]
    sub ah, '0'

    cmp ah, 1
    je Adicionar
    cmp ah, 2
    je Subtrair
    cmp ah, 3
    je Multiplicar
    cmp ah, 4
    je Dividir

    mov rcx, msgErro
    mov rdx, lmsgErro
    call mst_saida
    jmp exit

    Adicionar:
        mov rax, obVal1
        mov rbx, obVal2
        add rax, rbx
        jmp exit

    Subtrair:
        mov rax, obVal1
        mov rbx, obVal2
        sub rax, rbx
        jmp exit

    Multiplicar:
        ;mul bx
        jmp exit

    Dividir:
        ;div bx
        jmp exit

    exit:
        mov rcx, sLinha
        mov rdx, lsLinha
        call mst_saida
        mov rax, 1
        mov rbx, 0
        int 80h

mst_saida:
    mov rax, 4
    mov rbx, 1
    int 80h
    ret