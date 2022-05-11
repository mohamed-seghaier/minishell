/*
** EPITECH PROJECT, 2018
** gnl.c
** File description:
** gnl.c
*/

#include "../include/my.h"

void	my_memset(char *src, int l, int m)
{
	int	i = 0;

	for (i = 0; i < m; i += 1)
		src[i] = l;
}

int	my_strlen(char *str)
{
	int	i = 0;

	for (i = 0; str[i]; i += 1);
	return (i);
}

char	*my_strcat(char *src, char *dest)
{
	int	i = my_strlen(src);
	int	j = my_strlen(dest);
	int	k = 0;
	char	*tmp = malloc(sizeof(char) * (i + j) + 1);

	for (i = 0; src[i]; i += 1, k += 1)
		tmp[k] = src[i];
	for (i = 0; dest[i]; i += 1, k += 1)
		tmp[k] = dest[i];
	return (tmp);
}

char	*get_next_line(int fd)
{
	char	tmp[2];
	char	*dest = "";
	int	i = 0;
	int	j = 0;

	my_memset(dest, 0, my_strlen(dest));
	while ("Dali") {
		if ((read(fd, tmp, 1)) == -1)
			return (j == 0 ? NULL : dest);
		if (tmp[i] == '\n') {
			return (dest);
		}
		if ((tmp[0]) == 0)
			return (NULL);
		dest = my_strcat(dest, tmp);
		j += 1;
	}
}

char	*get_home(char *str)
{
	int	i = 0;
	int	j = 0;
	char	*dest = NULL;
	int	idx = 0;

	for (; str[i] != '='; i += 1);
	idx = (my_strlen(str) - i);
	if ((dest = malloc(sizeof(char) * idx + 1)) == NULL)
		return (NULL);
	i += 1;
	for (; str[i]; i += 1, j += 1)
		dest[j] = str[i];
	return (dest);
}
