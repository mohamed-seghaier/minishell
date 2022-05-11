/*
** EPITECH PROJECT, 2018
** unsetenv
** File description:
** unsetenv
*/

#include "../include/my.h"

void	do_unsetenv(t_line *shell, t_env **head)
{
	t_env	*tmp = (*head);
	char	*s;
	int	a = 1;
	int	b = 1;

	while (shell->cmd[b] != NULL) {
		s = my_strcat(shell->cmd[b], "=");
		while (tmp != NULL) {
			if (my_strncmp(tmp->str, s, my_strlen(s)) == 0)
				erase_node(head, a);
			else
				a += 1;
			tmp = tmp->next;
		}
		a = 1;
		b += 1;
		tmp = (*head);
	}
}

int	is_unsetenv(t_line *shell)
{
	if (shell->cmd[1] == NULL) {
		put_msg(2, "unsetenv: Too fet arguments.\n");
		return (shell->ret = 1);
	}
	do_unsetenv(shell, &shell->env);
	return (shell->ret = 0);
}
