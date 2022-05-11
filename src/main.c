/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** début du programme
*/

#include "../include/my.h"

int	main(UNU int argc, UNU char **argv, char **env)
{
	t_line	shell;

	shell.env = NULL;
	shell.cmd = NULL;
	shell.realpath = NULL;
	shell.ret = 0;
	shell.tab_env = env;
	if ((base(argc, argv, env, &shell)) == -1)
		return (84);
}

int	base(UNU int argc, UNU char **argv, char **env, t_line *shell)
{
	char	*str;
	char	**tab;
	char	**path;

	path = searcher(env, shell);
	signal(SIGINT, SIG_IGN);
	while (42) {
		my_printf("Dali_sh -> ");
		if ((str = get_next_line(0)) == NULL) {
			my_printf("exit\n");
			return (0);
		}
		str = my_epurstr(str);
		tab = my_strtab(str, ' ');
		my_exiter(tab);
		shell->cmd = tab;
		call_arg(shell, path);
	}
}

char	**my_strtab(char *str, char sep)
{
	char	**tab;
	int	idx_tab;
	int	i = 0;
	int	len = 0;
	int	j = 0;
	int	toto = my_eolen(str, sep) + sizeof(char *);

	if ((tab = malloc(sizeof(char *) * toto)) == NULL)
		return (NULL);
	for (idx_tab = 0; idx_tab < my_eolen(str, sep) + 1; idx_tab += 1) {
		for (; str[i] != sep && str[i]; i += 1, len += 1);
		if ((tab[idx_tab] = malloc(sizeof(char) * len + 1)) == NULL)
			return (NULL);
		remplitab(tab[idx_tab], str, j, sep);
		for (; str[j] != sep && str[j]; j += 1);
		len = 0;
		i += 1;
		j += 1;
	}
	tab[idx_tab] = NULL;
	return (tab);
}

char	*remplitab(char *dest, char *src, int j, char sep)
{
	int	idx = 0;

	for (idx = 0; src[j] != sep && src[j]; idx += 1, j += 1)
		dest[idx] = src[j];
	dest[idx] = 0;
	return (dest);
}

int	my_eolen(char *str, char sep)
{
	int	idx_len = 0;
	int	idx_str = 0;

	for (idx_len = 0; str[idx_str]; idx_str += 1)
		str[idx_str] == sep ? idx_len += 1 : 0;
	return (idx_len);
}
