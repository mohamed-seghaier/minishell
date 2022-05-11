/*
** EPITECH PROJECT, 2018
** searcher.c
** File description:
** chercheur de PATH
*/

#include "../include/my.h"

char	**searcher(char **env, t_line *shell)
{
	int	i = 0;
	char	*tmp = NULL;
	char	**path;

	for (; env[i] != NULL; i += 1) {
		if ((strcompar(env[i], "PATH=")) == 1)
			tmp = my_supestrcpy(env[i]);
		shell->env = add_node(shell->env, env[i]);
	}
	if (tmp == NULL) {
		path = malloc(sizeof(char *) * 4);
		path[0] = my_strdup("/usr/local/bin/");
		path[1] = my_strdup("/usr/bin/");
		path[2] = my_strdup("/bin/");
		path[3] = NULL;
	}
	else
		path = my_strtab(tmp, ':');
	return (path);
}

void	my_exiter(char **tab)
{
	char	*cmp = "exit";

	if (strcompar(cmp, tab[0]) == 1) {
		my_printf("exit\n");
		exit(0);
	}
}

int	strcompar(char *str, char *ing)
{
	int	i = 0;
	int	len = my_strlen(ing);
	int	cmp = 0;

	for (i = 0; str[i] && ing[i]; i += 1)
		cmp += (str[i] == ing[i] ? 1 : 0);
	return ((len == cmp ? (1) : 0));
}

char	*my_supestrcpy(char *str)
{
	char	*dest;
	int	i = 0;
	int	idx = 0;
	char	*path = "PATH=";
	int	len = my_strlen(str);

	for (idx = 0; path[idx]; idx += 1);
	if ((dest = malloc(sizeof(char) * (len - 4))) == NULL)
		return (NULL);
	for (i = 0; str[idx]; idx+= 1, i += 1)
		dest[i] = str[idx];
	dest[i] = 0;
	return (dest);
}

int	toto(char *str, char **cmd, char **env)
{
	pid_t	toto;
	int	i = 0;

	toto = fork();
	if (toto != 0)
		wait(&i);
	else {
		if (execve(str, cmd, env) == -1)
			return (-1);
		exit(0);
	}
	gest_segfault(i);
	return (1);
}
