# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 2)
    {
		char *str;

		str = "otavio";
		printf("%s = mine : %d (original : %d)\n", str, ft_strlen(str), (int)strlen(str));
		str = "ate";
		printf("%s = mine : %d (original : %d)\n", str, ft_strlen(str), (int)strlen(str));
		str = "ecole";
		printf("%s = mine : %d (original : %d)\n", str, ft_strlen(str), (int)strlen(str));
		str = "1234567890";
		printf("%s = mine : %d (original : %d)\n", str, ft_strlen(str), (int)strlen(str));
		str = "     42";
		printf("%s = mine : %d (original : %d)\n", str, ft_strlen(str), (int)strlen(str));
		str = "";
		printf("%s = mine : %d (original : %d)\n", str, ft_strlen(str), (int)strlen(str));
	}
}