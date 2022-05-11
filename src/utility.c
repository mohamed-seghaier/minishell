/*
** EPITECH PROJECT, 2018
** utility
** File description:
** utility
*/

#include "../include/my.h"

char	*my_strdup(char *str)
{
	char	*elem = malloc(sizeof(char) * my_strlen(str) + 1);
	int	i = -1;

	if (!elem)
		return (NULL);
	while (str[++i])
		elem[i] = str[i];
	return (elem);
}

void	print_tab(char **tab)
{
	int	i = -1;

	while (tab[++i]) {
		printf("tab[%d] = %s\n", i, tab[i]);
	}
}

void	put_msg(int i, char *str)
{
	write(i, str, my_strlen(str));
}

int	my_strcmp(char *s1, char *s2)
{
	int	i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
		i += 1;
	if (s1[i] < s2[i])
		return (-1);
	if (s1[i] > s2[i])
		return (1);
	return (0);
}

int	tab_length(char **tab)
{
	int	i = -1;
	int	n = 0;

	while (tab[++i]) {
		n += 1;
	}
	return (n);
}
