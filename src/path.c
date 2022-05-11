/*
** EPITECH PROJECT, 2018
** path
** File description:
** path
*/

#include "../include/my.h"

int	choose_path(t_line *tools, char **path)
{
	int	i = -1;
	char	*str = NULL;

	while (path[++i]) {
		str = my_strcat(path[i], "/");
		str = my_strcat(str, tools->cmd[0]);
		if (access(str ,F_OK) == 0) {
			tools->realpath = str;
			return (0);
		}
		str = NULL;
	}
	if (access(tools->cmd[0], F_OK) == 0) {
		tools->realpath = tools->cmd[0];
		return (0);
	}
	return (-1);
}
