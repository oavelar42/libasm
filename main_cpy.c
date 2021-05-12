#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

char	*ft_strcpy(char *dest, const char *src);

int			main(int argc, char **argv)
{
	if (argc, "ft_strcpy")
	{
		char	buf[20] = {0};
	char	buff[20] = {0};

	printf("----------------------------------\n");
	printf(GREEN "ft_strcpy :"RESET"\n");
	printf("	 original: %s\n", strcpy(buf, ""));
	printf("	 my: %s\n", ft_strcpy(buff, ""));
	printf("	 original: %s\n", strcpy(buf, "abc"));
	printf("	 my: %s\n", ft_strcpy(buff, "abc"));
	printf("	 original: %s\n", strcpy(buf, "d\0efa"));
	printf("	 my: %s\n", ft_strcpy(buff, "d\0efa"));
	printf("	 original: %s\n", strcpy(buf, "hello world"));
	printf("	 my: %s\n", ft_strcpy(buff, "hello world"));
	printf("	 original: %s\n", strcpy(buf, "     ecola 42"));
	printf("	 my: %s\n", ft_strcpy(buff, "     ecola 42"));
	printf("\n");
	}
}


/*nasm -f elf64 ft_strcpy.s -o cpy.o
gcc main_cpy.c cpy.o 
./a.out*/