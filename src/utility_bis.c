/*
** EPITECH PROJECT, 2018
** utility_bis
** File description:
** utility_bis
*/

#include "../include/my.h"

int	is_alph(char *str)
{
	int	i = 0;

	while (str[i]) {
		if ((str[i] < 'A' || str[i] > 'Z') &&
		    (str[i] < 'a' || str[i] > 'z') &&
		    (str[i] < '0' || str[i] > '9'))
			return (0);
		i += 1;
	}
	return (1);
}

int	my_strncmp(char *s1, char *s2, int n)
{
	int	i = 0;

	while (i < n && s1[i] != '\0' && s2[i] != '\0') {
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
		i = i + 1;
	}
	return (0);
}
