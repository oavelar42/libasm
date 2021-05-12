#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

int		ft_strcmp(char *s1, char *s2);

int main(int argc, char **argv)
{
	if (argc, "ft_strcmp")
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
}