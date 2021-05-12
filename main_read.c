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

int		ft_read(int fd, char *str, int byte);

int main(int argc, char **argv)
{
    if (argc, "ft_read")
    {  
        int	fd = open("to_read.txt", O_RDONLY);
		char	buffer[200] = {0};
		char	buffer2[200] = {0};
		char	buffer3[200] = {0};
		int	i;

		i = ft_read(fd, buffer, 199);
		buffer[i] = 0;
		printf("%d\n", i);
		printf("%s\n", buffer);
		perror("errno");

		i = ft_read(fd, buffer2, 199);
		buffer2[i] = 0;
		printf("%d\n", i);
		printf("%s\n", buffer2);
		perror("errno");

		i = ft_read(fd, buffer3, 199);
		buffer3[i] = 0;
		printf("%d\n", i);
		printf("%s\n", buffer3);
		perror("errno");
	}
}