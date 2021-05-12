#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

size_t		ft_strlen(const char *str);

int main(int argc, char **argv)
{
	if (argc, "ft_strlen")
	{
		char	s1[] = "";
		char	s2[] = "\0";
		char	s3[] = "ABC";
		char	s4[] = "ABC\0EF";
		char	s5[] = "0123456789012345678901234567890123456789012345678901234567890123456789";
		char	s6[] = "easy     asm";
		char	s7[] = "   next ";

		printf(GREEN "ft_strlen :"RESET"\n");
		printf("	ori : %ld\n", strlen(s1));
		printf("	my : %ld\n", ft_strlen(s1));
		printf("	ori : %ld\n", strlen(s2));
		printf("	my : %ld\n", ft_strlen(s2));
		printf("	ori : %ld\n", strlen(s3));
		printf("	my : %ld\n", ft_strlen(s3));
		printf("	ori : %ld\n", strlen(s4));
		printf("	my : %ld\n", ft_strlen(s4));
		printf("	ori : %ld\n", strlen(s5));
		printf("	my : %ld\n", ft_strlen(s5));
		printf("	ori : %ld\n", strlen(s6));
		printf("	my : %ld\n", ft_strlen(s6));
		printf("	ori : %ld\n", strlen(s7));
		printf("	my : %ld\n", ft_strlen(s7));

	}
	/*if (argc != 2)
    {
		char *str;

		str = "otavio";
		printf("%s = my : %d (original : %d)\n", str, ft_strlen(str), (int)strlen(str));
		str = "ate";
		printf("%s = my : %d (original : %d)\n", str, ft_strlen(str), (int)strlen(str));
		str = "ecole";
		printf("%s = my : %d (original : %d)\n", str, ft_strlen(str), (int)strlen(str));
		str = "1234567890";
		printf("%s = my : %d (original : %d)\n", str, ft_strlen(str), (int)strlen(str));
		str = "     42";
		printf("%s = my : %d (original : %d)\n", str, ft_strlen(str), (int)strlen(str));
		str = "";
		printf("%s = my : %d (original : %d)\n", str, ft_strlen(str), (int)strlen(str));
	}*/
}