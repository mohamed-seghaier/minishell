/*
** EPITECH PROJECT, 2018
** exec
** File description:
** exec
*/

#include "../include/my.h"

int	error_erno(t_line *shell)
{
	if (errno == ENOEXEC) {
		put_msg(2, shell->cmd[0]);
		put_msg(2, ": Exec format error. Wrong Architecture.\n");
		return (shell->ret = 1);
	}
	if (errno == EACCES) {
		put_msg(2, shell->cmd[0]);
		put_msg(2, ": Permission denied.\n");
		return (shell->ret = 1);
	}
	return (shell->ret);
}

int	launch_exec(t_line *shell)
{
	int	value = 0;
	pid_t	pid = fork();

	if (pid) {
		waitpid(pid, &value, 0);
		shell->ret = value/256;
		gest_segfault(value);
	}
	else {
		if (execve(shell->realpath, shell->cmd, shell->tab_env) == -1)
			return (error_erno(shell));
	}
	return (shell->ret);
}
