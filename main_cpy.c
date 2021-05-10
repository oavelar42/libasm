# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
#define _DEF_	"\x1B[0m"
#define _RED_	"\x1B[31m"
#define _GRN_	"\x1B[32m"
#define _YEL_	"\x1B[33m"
#define _BLU_	"\x1B[34m"
#define _MAG_	"\x1B[35m"
#define _CYN_	"\x1B[36m"
#define _WHT_	"\x1B[37m"

int		main(void)
{

	char	*s0 = "";
	char	*s10 = "1234567890";
	char	*s100 = "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
	char	s1[500];
	char	s2[500];
	char	*s3 = "zzz";

	printf("\n%s%17s%s\n", "\x1B[35m", "#ft_strcpy#", _DEF_);
	printf("%s--------------------%s\n", "\x1B[35m", _DEF_);
	printf("%s%10s%s | %s%-10s%s\n", _GRN_, "orig",_DEF_, _YEL_, "my", _DEF_);
	printf("%10s | %-10s\n", strcpy(s1, ""), ft_strcpy(s2, ""));
	printf("%10s | %-10s\n", strcpy(s1, s3), ft_strcpy(s2, s3));
	printf("%10s | %-10s\n", strcpy(s1, s10), ft_strcpy(s2, s10));
	printf("%s%-5s%s%s\n%s%-5s%s%s\n", _GRN_, "orig",_DEF_, strcpy(s1, s100), _YEL_, "my", _DEF_, ft_strcpy(s2, s100));
}

nasm -f elf64 ft_strcpy.s -o cpy.o
gcc main_cpy.c cpy.o 
./a.out


/*int main(int argc, char **argv)
{
    if (argc != 2)
    {
		char	dest[64];
		char	*src;

		src = "hola";
		printf("src = '%s'; dest = '%s' ('%s')\n", src, ft_strcpy(dest, src), strcpy(dest, src));
		src = "";
		printf("src = '%s'; dest = '%s' ('%s')\n", src, ft_strcpy(dest, src), strcpy(dest, src));
		src = "0123456789abcedef";
		printf("src = '%s'; dest = '%s' ('%s')\n", src, ft_strcpy(dest, src), strcpy(dest, src));
		src = "ecole 42";
		printf("src = '%s'; dest = '%s' ('%s')\n", src, ft_strcpy(dest, src), ft_strcpy(dest, src));
    }
}*/