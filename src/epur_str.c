/*
** EPITECH PROJECT, 2018
** epurstr
** File description:
** epuration du totorino
*/

#include "../include/my.h"

int	my_deleter(char	*str)
{
	int	del = 0;
	int	idx = 0;

	for (del = 0, idx = 0; str[idx]; idx += 1) {
		del += (str[idx] == 9 ? 1 : 0);
		del += (str[idx] == 11 ? 1 : 0);
		del += (str[idx] == 32 && str[idx + 1] == 32 ? 1 : 0);
	}
	return (del);
}

char	*my_strecopy(char *src, char *dest, int base)
{
	int	idx_s = 0;
	int	idx_d = 0;

	for (idx_s = 0; idx_d < base;) {
		for (; src[idx_s] == 32 && src[idx_s + 1] == 32;)
			idx_s += 1;
		idx_s += (src[idx_s] == 9 ? 1 : 0);
		idx_s += (src[idx_s] == 11 ? 1 : 0);
		idx_s += (idx_d == 0 && src[idx_s] == 32 ? 1 : 0);
		for (; src[idx_s] == 32 && src[idx_s + 1] == 32;)
			idx_s += 1;
		if (src[idx_s] != 9 || src[idx_s] != 11) {
			dest[idx_d] = src[idx_s];
			idx_s += 1;
			idx_d += 1;
		}
	}
	dest[idx_d] = 0;
	return (dest);
}

char	*my_epurstr(char *str)
{
	int	del = my_deleter(str);
	int	idx_del = (my_strlen(str) - del + 1);
	char	*dest;

	if ((dest = malloc(sizeof(char) * (my_strlen(str) - del + 1))) == NULL)
		return (NULL);
	str = my_strecopy(str, dest, idx_del);
	str = my_strecopy(str, dest, idx_del);
	return (dest);
}

void	gest_segfault(int i)
{
	int	toto = 0;

	if (WTERMSIG(i) == 11) {
		put_msg(2, "Segmentation fault");
		toto = 1;
	}
	WTERMSIG(i) == 8 ? put_msg(2, "Floating exception"), (toto = 1) : 0;
	if (WCOREDUMP(i))
		put_msg(2, " (core dumped)");
	if (toto != 0)
		put_msg(2, "\n");
}
