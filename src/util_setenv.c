/*
** EPITECH PROJECT, 2018
** util
** File description:
** util
*/

#include "../include/my.h"

void	ad_setenv(t_line *tools, t_env *shell, char *str)
{
	if (tools->cmd[2] == NULL)
		shell = add_node(shell, my_strcat(tools->cmd[1], "="));
	else
		shell = add_node(shell, my_strcat(str, tools->cmd[2]));
}

void	rep_setenv(t_line *tools, t_env *tmp, char *str)
{
	if (tools->cmd[2] == NULL)
		tmp->str = my_strcat(tools->cmd[1], "=");
	else
		tmp->str = my_strcat(str, tools->cmd[2]);
}
