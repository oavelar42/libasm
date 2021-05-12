
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libasm.h"

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_write(int fd, char *str, int byte);
int		ft_read(int fd, char *str, int byte);
char	*ft_strdup(const char *s);

int			main(int argc, char **argv)
{
	if (argc != 2)
		printf("Choose an appropiate option to test:\n\tft_strlen: strlen\n\tft_strcpy: strcpy\n\tft_strcmp: strcmp\n\tft_write:  write\n\tft_read:   read\n\tft_strdup: strdup\n");
	else if (!strcmp(argv[1], "strlen"))
	{
		char *str;

		str = "hOLa";
		printf("%s = %d (%d)\n", str, ft_strlen(str), (int)strlen(str));
		str = "";
		printf("%s = %d (%d)\n", str, ft_strlen(str), (int)strlen(str));
		str = "\t3por1";
		printf("%s = %d (%d)\n", str, ft_strlen(str), (int)strlen(str));
		str = "1234567890";
		printf("%s = %d (%d)\n", str, ft_strlen(str), (int)strlen(str));
		// str = NULL;
		// printf("%s : %d (%d)\n", str, ft_strlen(str), (int)strlen(str));
	}
	else if (!strcmp(argv[1], "strcpy"))
	{
		char	dest[64];
		char	*src;

		src = "hola";
		printf("src = '%s'; dest = '%s' ('%s')\n", src, ft_strcpy(dest, src), strcpy(dest, src));
		src = "";
		printf("src = '%s'; dest = '%s' ('%s')\n", src, ft_strcpy(dest, src), strcpy(dest, src));
		src = "0123456789abcedef";
		printf("src = '%s'; dest = '%s' ('%s')\n", src, ft_strcpy(dest, src), strcpy(dest, src));
		// src = NULL;
		// printf("src: '%s'; dest: '%s' ('%s')\n", src, ft_strcpy(dest, src), ft_strcpy(dest, src));
	}
	else if (!strcmp(argv[1], "strcmp"))
	{
		char	*s1;
		char	*s2;

		s1 = "hola";
		s2 = "hola";
		printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
		s1 = "hol";
		s2 = "hola";
		printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
		s1 = "hola";
		s2 = "hol";
		printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
		s1 = "hola";
		s2 = "holb";
		printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
		s1 = "";
		s2 = "holb";
		printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
		s1 = "";
		s2 = "hola";
		printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
		s1 = "hola";
		s2 = "";
		printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
		s1 = "";
		s2 = "";
		printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
		//s1 = "hola";
		// s2 = NULL;
		// printf("'%s' : '%s' = %d (%d)\n", s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2));
	}
	else if (!strcmp(argv[1], "write"))
	{
		int	i,j;

		i = ft_write(1, "hola\n", 5);
		j = write(1, "hola\n", 5);
		printf ("num bytes = %d (%d)\n", i, j);
		perror("errno");

		i = ft_write(-1, "hola\n", 5);
		j = write(1, "hola\n", 5);
		printf ("num bytes = %d (%d)\n", i, j);
		perror("errno");

		i = ft_write(1, "hola\n", 5);
		j = write(-1, "hola\n", 5);
		printf ("num bytes = %d (%d)\n", i, j);
		perror("errno");

		i = ft_write(-1, "hola\n", 5);
		j = write(-1, "hola\n", 5);
		printf ("num bytes = %d (%d)\n", i, j);
		perror("errno");

		i = ft_write(1, NULL, 5);
		j = write(1, "hola\n", 5);
		printf ("num bytes = %d (%d)\n", i, j);
		perror("errno");

		i = ft_write(1, "hola\n", 5);
		j = write(1, NULL, 5);
		printf ("num bytes = %d (%d)\n", i, j);
		perror("errno");

		i = ft_write(1, NULL, 5);
		j = write(1, NULL, 5);
		printf ("num bytes = %d (%d)\n", i, j);
		perror("errno");
	}
	else if (!strcmp(argv[1], "read"))
	{
		int	fd = open("main.c", O_RDONLY);
		char	buffer[100] = {0};
		char	buffer2[100] = {0};
		char	buffer3[100] = {0};
		int	i;

		i = ft_read(fd, buffer, 99);
		buffer[i] = 0;
		printf("%d\n", i);
		printf("%s\n", buffer);
		perror("errno");

		i = ft_read(fd, NULL, 99);
		buffer2[i] = 0;
		printf("%d\n", i);
		printf("%s\n", buffer2);
		perror("errno");

		i = ft_read(-1, buffer3, 99);
		buffer3[i] = 0;
		printf("%d\n", i);
		printf("%s\n", buffer3);
		perror("errno");
	}
	else if (!strcmp(argv[1], "strdup"))
	{
		char	 *d, *str;

		str = "buenos dias";
		d = ft_strdup(str);
		perror("errno");
		printf("duplicated:         %s\n", d);
		printf("allocation address: %p\n", d);
		//printf("bytes printed:      %d\n", (int)strlen(d));  -----  si malloc = NULL; strlen(NULL) = segfault
		free(d);
	}
	else
	{
		printf("Invalid option. ");
		printf("Choose an appropiate option to test:\n\tft_strlen: strlen\n\tft_strcpy: strcpy\n\tft_strcmp: strcmp\n\tft_write:  write\n\tft_read:   read\n\tft_strdup: strdup\n");
	}

	return (0);
}


/*------------------------------------------------------------*/

#include "libasm.h"
#include <errno.h>
#include <error.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

static void	check_strlen(void)
{
	char	s1[] = "";
	char	s2[] = "\0";
	char	s3[] = "ABC";
	char	s4[] = "ABC\0EF";
	char	s5[] = "0123456789012345678901234567890123456789012345678901234567890123456789";
	
	printf(GREEN "ft_strlen :"RESET"\n");
	printf("	len : %zu\n", strlen(s1));
	printf("	flen : %zu\n", ft_strlen(s1));
	printf("	len : %zu\n", strlen(s2));
	printf("	flen : %zu\n", ft_strlen(s2));
	printf("	len : %zu\n", strlen(s3));
	printf("	flen : %zu\n", ft_strlen(s3));
	printf("	len : %zu\n", strlen(s4));
	printf("	flen : %zu\n", ft_strlen(s4));
	printf("	len : %zu\n", strlen(s5));
	printf("	flen : %zu\n", ft_strlen(s5));
	printf("	len : SEGMENTATION FAULT\n");
	//printf("	len : %zu\n", strlen(NULL));
	printf("	flen : %zu\n", ft_strlen(NULL));
}

void	check_strcpy(void)
{
	char	buf[12] = {0};
	char	buff[12] = {0};

	printf("----------------------------------\n");
	printf(GREEN "ft_strcpy :"RESET"\n");
	printf("	 cpy: %s\n", strcpy(buf, ""));
	printf("	 fcpy: %s\n", ft_strcpy(buff, ""));
	printf("	 cpy: %s\n", strcpy(buf, "abc"));
	printf("	 fcpy: %s\n", ft_strcpy(buff, "abc"));
	printf("	 cpy: %s\n", strcpy(buf, "d\0ef"));
	printf("	 fcpy: %s\n", ft_strcpy(buff, "d\0ef"));
	printf("	 cpy: SEGMENTATION FAULT\n");
	//printf("	 cpy: %s\n", strcpy(buff, NULL));
	printf("	 fcpy: %s\n", ft_strcpy(buff, NULL));
	printf("\n");
}

void	check_strcmp(void)
{
	char	s1[] = "hello";
	char	s2[] = "helloworld";
	char	s3[] = "";
	char	s4[] = "hello\0a";
	char	s5[] = "hello\0b";
	char	s6[] = "hellow";
	char	s7[] = "\x01";
	char	s8[] = "\x01\x01";
	char	s9[] = "\x01\x02";
	char	s0[] = "\0";

	printf("----------------------------------\n");
	printf(GREEN "ft_strcmp :"RESET"\n");
	printf("[00]\n");
	printf("	cmp : %i\n", strcmp(s1, s2));
	printf("	fcmp : %i\n", ft_strcmp(s1, s2));
	printf("[01]\n");
	printf("	cmp : %i\n", strcmp(s1, s1));
	printf("	fcmp : %i\n", ft_strcmp(s1, s1));
	printf("[02]\n");
	printf("	cmp : %i\n", strcmp(s2, s1));
	printf("	fcmp : %i\n", ft_strcmp(s2, s1));
	printf("[03]\n");
	printf("	cmp : %i\n", strcmp(s1, s3));
	printf("	fcmp : %i\n", ft_strcmp(s1, s3));
	printf("[04]\n");
	printf("	cmp : %i\n", strcmp(s4, s5));
	printf("	fcmp : %i\n", ft_strcmp(s4, s5));
	printf("[05]\n");
	printf("	cmp : %i\n", strcmp(s1, s4));
	printf("	fcmp : %i\n", ft_strcmp(s1, s4));
	printf("[06]\n");
	printf("	cmp : %i\n", strcmp(s6, s1));
	printf("	fcmp : %i\n", ft_strcmp(s6, s1));
	printf("[07]\n");
	printf("	cmp : %i\n", strcmp(s1, s6));
	printf("	fcmp : %i\n", ft_strcmp(s1, s6));
	printf("[08]\n");
	printf("	cmp : %i\n", strcmp(s4, s6));
	printf("	fcmp : %i\n", ft_strcmp(s4, s6));
	printf("[09]\n");
	printf("	cmp : %i\n", strcmp(s3, s3));
	printf("	fcmp : %i\n", ft_strcmp(s3, s3));
	printf("[10]\n");
	printf("	cmp : %i\n", strcmp(s7, s7));
	printf("	fcmp : %i\n", ft_strcmp(s7, s7));
	printf("[11]\n");
	printf("	cmp : %i\n", strcmp(s7, s9));
	printf("	fcmp : %i\n", ft_strcmp(s7, s9));
	printf("[12]\n");
	printf("	cmp : %i\n", strcmp(s9, s8));
	printf("	fcmp : %i\n", ft_strcmp(s9, s8));
	printf("[13]\n");
	printf("	cmp : SEGMENTATION FAULT\n");
//	printf("	cmp : %i\n", strcmp(s3, NULL));
	printf("	fcmp : %i\n", ft_strcmp(s3, NULL));
	printf("[14]\n");
	printf("	cmp : SEGMENTATION FAULT\n");
//	printf("	cmp : %i\n", strcmp(NULL, NULL));
	printf("	fcmp : %i\n", ft_strcmp(NULL, NULL));
	printf("[15]\n");
	printf("	cmp : SEGMENTATION FAULT\n");
//	printf("	cmp : %i\n", strcmp(NULL, s3));
	printf("	fcmp : %i\n", ft_strcmp(NULL, s3));
	printf("\n");
	printf("[16]\n");
	printf("	cmp : %i\n", strcmp(s0, s3));
	printf("	fcmp : %i\n", ft_strcmp(s0, s3));
	printf("[17]\n");
	printf("	cmp : %i\n", strcmp(s0, s0));
	printf("	fcmp : %i\n", ft_strcmp(s0, s0));
	printf("[18]\n");
	printf("	cmp : %i\n", strcmp(s1, s0));
	printf("	fcmp : %i\n", ft_strcmp(s1, s0));
}

void	check_write(void)
{
	int	fd;
	int	fd2;
	char	*str = NULL;
	char	buf[11] = "abcdefghij";

	fd = open("./test", O_RDWR);
	fd2 = open("./test", O_RDONLY);
	
	printf("----------------------------------\n");
	printf(GREEN"ft_write :"RESET"\n");
	printf(YELLOW"	str = \"abc\""RESET"\n");
	str = "abc";
	// 9 : Bad file descriptor (RDONLY)
	printf(" TEST 1\n");
	errno = 0;
	printf("		|wr : %zd\n", write(fd2, str, 2));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(fd2, str, 2));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 9 : Bad file descriptor (RANDOM)
	printf(" TEST 2\n");
	errno = 0;
	printf("		|wr : %zd\n", write(4, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(4, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 14 : Bad address
	printf(" TEST 3\n");
	errno = 0;
	printf("		|wr : %zd\n", write(fd, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(fd, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 0 : Write on file
	printf(" TEST 4\n");
	errno = 0;
	printf("		|wr : %zd\n", write(fd, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(fd, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	printf(" TEST 5\n");
	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	printf(" TEST 6\n");
	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	printf(" TEST 7\n");
	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	printf(" TEST 8\n");
	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	printf(" TEST 9\n");
	errno = 0;
	printf("		|wr : %zd\n", write(4, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(4, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	printf(" TEST 10\n");
	errno = 0;
	printf("		|wr : %zd\n", write(1, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	str = NULL;
	printf(YELLOW"	str = NULL"RESET"\n");
	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 0));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 0));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(4, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(4, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	str = "";
	printf(YELLOW"	str = \"\""RESET"\n");
	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 0));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 0));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(fd, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(fd, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(4, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(4, str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, "bonjour", 7));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, "bonjour", 7));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(98123, "", 1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(98123, "", 1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(42, NULL, 7));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(42, NULL, 7));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, &buf, 7));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, &buf, 7));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|wr : %zd\n", write(1, buf, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|wr : %zd\n", ft_write(1, buf, 4));
	printf("	unistd.unistd.hh	%i : %s\n", errno, strerror(errno));
	printf("\n");
}

void	check_read(void)
{
	int	fd;
	char	*str = NULL;

	fd = open("./Makefile", O_RDONLY);

	// 0 : Success
	printf("----------------------------------\n\n");
	printf(GREEN"ft_read :"RESET"\n");
	printf(YELLOW"	str = \"abc\""RESET"\n");
	str = "abc";
	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 2));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 2));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 9 : Bad file descriptor
	errno = 0;
	printf("		|rd : %zd\n", read(410, &str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(410, &str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	// 14 : Bad address
	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");


	// Read stdin
	printf("Write some text from stdin\n");
	errno = 0;
	printf("		|rd : %zd\n", read(1, &str, 25));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(1, &str, 25));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");


	fd = open("./Makefile", O_RDONLY);
	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(410, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(410, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	fd = open("./Makefile", O_RDONLY);
	str = NULL;
	printf(YELLOW"	str = NULL"RESET"\n");
	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 0));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 0));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(410, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(410, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	fd = open("./Makefile", O_RDONLY);
	str = "";
	printf(YELLOW"	str = \"\""RESET"\n");
	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 0));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 0));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 3));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 4));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(410, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(410, &str, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, &str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, &str, -1));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");
	
	char	buf[32];
	errno = 0;
	printf("		|rd : %zd\n", read(98123, buf, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(98123, buf, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(fd, buf, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(fd, buf, 5));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("		|rd : %zd\n", read(42, NULL, 7));
	printf("		%i : %s\n", errno, strerror(errno));
	errno = 0;
	printf("		|rd : %zd\n", ft_read(42, NULL, 7));
	printf("		%i : %s\n", errno, strerror(errno));
	printf("\n");
}

void	check_strdup(void)
{
	char	s1[] = "abc";
	char	s2[] = "abcdefghijklmnopqstuvwxyz";
	char	s3[] = "";
	char	s4[] = "\0";
	char	s5[] = "abcd\0fgh";

	printf("----------------------------------\n");
	printf(GREEN"ft_strdup :"RESET"\n");
	printf("	dup : %s\n", strdup(s1));
	printf("	fdup : %s\n", ft_strdup(s1));
	printf("\n");
	printf("	dup : %s\n", strdup(s2));
	printf("	fdup : %s\n", ft_strdup(s2));
	printf("\n");
	printf("	dup : %s\n", strdup(s3));
	printf("	fdup : %s\n", ft_strdup(s3));
	printf("\n");
	printf("	dup : SEGMENTATION FAULT\n");
//	printf("	dup : %s\n", strdup(NULL));
	printf("	fdup : %s\n", ft_strdup(NULL));
	printf("\n");
	printf("	dup : %s\n", strdup(s4));
	printf("	fdup : %s\n", ft_strdup(s4));
	printf("\n");
	printf("	dup : %s\n", strdup(s5));
	printf("	fdup : %s\n", ft_strdup(s5));
	printf("\n");
}

/*

-*/