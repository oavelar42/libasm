; int        ft_strlen(char *s)
			section	.text
			global	ft_strlen
ft_strlen:										;(char *s) = rdi
			xor		rax, rax					;rax = 0;
loop:
			cmp		byte [rdi + rax], 0x0
			jz		exit						;when s[i] == 0, exit
			inc		rax                         ; inc == 'i++'
			jne 	loop                        ; jne == '!='
exit:
			ret