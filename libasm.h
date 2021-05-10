#ifndef LIBASM_H
# define LIBASM_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_write(int fd, char *buff, size_t count);
size_t	ft_read(int fd, char *buf, size_t count);
char	*ft_strdup(char *s);

#endif