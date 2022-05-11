/*
** EPITECH PROJECT, 2018
** built
** File description:
** built
*/

#include "../include/my.h"

int	is_built(t_line *shell)
{
	if (my_strcmp(shell->cmd[0], "env") == 0)
		return (is_env(shell));
	else if (my_strcmp(shell->cmd[0], "setenv") == 0)
		return (is_setenv(shell));
	else {
		if (my_strcmp(shell->cmd[0], "unsetenv") == 0)
			return (is_unsetenv(shell));
		else if (my_strcmp(shell->cmd[0], "cd") == 0) {
			return (cdfunction(shell->cmd, shell->tab_env));
		}
	}
	return (-1);
}
