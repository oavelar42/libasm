# libasm
<h2>WORK IN PROGRESS</h2>
In computer programming, assembly language ,often abbreviated asm, is any low-level programming language
Assembly is tricky to learn, in part, because there are several flavours (AT&T or Intel / 32bit or 64bit / Linux or Mac). So when checking out Assembly resources to complete the libasm project keep in mind a few things:

The calling convention sets a few rules:
- rdi - used to pass 1st argument to functions
- rsi - used to pass 2nd argument to functions
- rdx - used to pass 3rd argument to functions
- rcx - used to pass 4th argument to functions
- r8 - used to pass 5th argument to functions
- r9 - used to pass 6th argument to functions
- rax - used to define the return value of functions

For run with gcc '.c'
- First step you need to compile your ".s" = nasm -f elf 64 <name.s> -o <name.o>
- Next you need to compile your ".c"       = gcc <name.c> <name.o>
-                                          = ./a.out
