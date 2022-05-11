/*
** EPITECH PROJECT, 2018
** setenv
** File description:
** setenv
*/

#include "../include/my.h"

int	is_env(t_line *shell)
{
	print_list(shell->env);
	return (shell->ret = 0);
}

int	bad_setenv(t_line *shell)
{
	if (is_alph(shell->cmd[1]) != 1) {
		put_msg(2, ERR1);
		return (shell->ret = 1);
	}
	if (shell->cmd[1][0] >= '0' && shell->cmd[1][0] <= '9') {
		put_msg(2, ERR);
		return (shell->ret = 1);
	}
	return (0);
}

int	is_setenv(t_line *shell)
{
	if (shell->cmd[1] == NULL) {
		is_env(shell);
		return (shell->ret);
	}
	else if (tab_length(shell->cmd) > 3) {
		put_msg(2, "setenv: Too many arguments.\n");
		return (shell->ret = 1);
	}
	else if (bad_setenv(shell) == 1)
		return (shell->ret);
	do_setenv(shell);
	return (shell->ret = 0);
}

void	do_setenv(t_line *shell)
{
	t_env	*tmp = shell->env;
	char	*s1 = my_strcat(shell->cmd[1], "=");
	int	i = 0;
	int	j = 0;

	while (tmp != NULL) {
		if (my_strncmp(tmp->str, s1, my_strlen(s1)) == 0 && j == 0) {
			rep_setenv(shell, tmp, s1);
			j = 1;
		}
		tmp = tmp->next;
		i += 1;
	}
	if (j == 0)
		ad_setenv(shell, shell->env, s1);
}
