#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <fcntl.h>
#include <stdlib.h>
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

size_t	ft_write(int fd, const void *buf, size_t count);

int main (int argc, char **argv)
{
    if (argc, "ft_write")
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
}