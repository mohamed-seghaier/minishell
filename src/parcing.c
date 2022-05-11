/*
** EPITECH PROJECT, 2018
** parceuz.c
** File description:
** je l'ai appelé comme ça pour rien
*/

#include "../include/my.h"

void	my_pathing(char	**path, char **cmd, char **env)
{
	int	i = 0;
	char	*str;
	int	test = 0;

	for (; path[i] != NULL; i += 1) {
		str = my_strcat(path[i], "/");
		str = my_strcat(str, cmd[0]);
		if (access(str, F_OK) != -1) {
			my_executer(str, cmd, env);
			test = 1;
		}
		free(str);
		if (path[i + 1] == NULL && test == 0
		    && toto(cmd[0], cmd, env) != 1) {
			my_sputstr(cmd[0]);
			my_sputstr(": Command not found.\n");
			exit(0);
		}
	}
}

void	my_executer(char *str, char **cmd, char **env)
{
	pid_t	toto;
	int	i = 0;

	toto = fork();
	if (toto != 0)
		wait(&i);
	else {
		execve(str, cmd, env);
		exit(0);
	}
}

int	my_cder(char **tab)
{
	if (strcompar(tab[0], "cd") == 1)
		return (1);
	return (0);
}

int	cdfunction(char **tab, char **env)
{
	char	*tmp = NULL;
	char	*home = NULL;
	int	i = 0;

	if (!tab[1] || strcompar(tab[1], "home") == 1
	|| strcompar(tab[1], "~") == 1) {
		for (i = 0; env[i] != NULL; i += 1)
			if (env[i][0] == 'H' && env[i][1] == 'O'
			    && env[i][2] == 'M' && env[i][3] == 'E')
				home = get_home(env[i]);
		home = my_strcat(home, "/");
		chdir(home);
	}
	else {
		tmp = my_strcat(tab[1], "/");
		if (chdir(tmp) == -1)
			my_sputstr("Not a directory\n");
	}
	return (1);
}

void	switcher(char **tab, int boolean, char **env)
{
	boolean == 1 ? cdfunction(tab, env) : 0;
}
