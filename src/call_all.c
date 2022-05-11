/*
** EPITECH PROJECT, 2018
** call
** File description:
** call
*/

#include "../include/my.h"

void	call_arg(t_line *shell, char **path)
{
	if (is_built(shell) >= 0);
	else if (choose_path(shell, path) == 0) {
		launch_exec(shell);
	}
	else {
		put_msg(2, shell->cmd[0]);
		put_msg(2, ": Command not found.\n");
		shell->ret = 1;
	}
}
