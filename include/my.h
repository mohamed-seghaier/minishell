/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** header
*/

#ifndef	_MY_H_
#define	_MY_H_

#define	UNU __attribute__((unused))
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <signal.h>
#include <errno.h>

#define	ERR	"setenv: Variable name must begin with a letter.\n"
#define	ERR1	"setenv: Variable name must contain alphanumeric characters.\n"

typedef	struct	s_env {
	char	*str;
	struct	s_env *next;
} t_env;

typedef	struct	s_line {
	char	**tab;
	char	*str;
	char	**path;
	char	*realpath;
	t_env	*env;
	char	**cmd;
	int	ret;
	char	**tab_env;
} t_line;

/*PARCEUZ.C*/
int	my_cder(char **);
void	switcher(char **, int, char **);
int	cdfunction(char **, char **);
void	my_executer(char *, char **, char **);
void	my_pathing(char **, char **, char **);

/*SEARCHER.C*/
void	my_exiter(char **);
int	strcompar(char *, char *);
char	**searcher(char **env, t_line *shell);
int	toto(char *, char **, char **);
char	*my_supestrcpy(char *);

/*GET_NEXT_LINE.C*/
char	*get_home(char *);
char    *get_next_line(int fd);
void	my_memset(char *src, int l, int m);
int	my_strlen(char *str);
char	*my_strcat(char *, char *);

/*EPURE_STR.C*/
char	*my_epurstr(char *);
char	*my_strecopy(char *, char *, int);
int	my_deleter(char *);
void	gest_segfault(int);

/*MAIN.C*/
int	my_eolen(char *, char);
int	main(int argc, char **argv, char **env);
int	base(int argc, char **argv, char **env, t_line *shell);
char	**my_strtab(char *, char);
char	*remplitab(char *, char *, int, char);

/*LIST.C*/
t_env	*add_node(t_env *, char *);
void	print_list(t_env *);
int	list_length(t_env *);
int	erase_node(t_env **, int);

/*UTILITY.C*/
char	*my_strdup(char *);
void	print_tab(char **);
void	put_msg(int, char *);;
int	my_strcmp(char *, char *);
int	tab_length(char **);

/*UTILITY_BIS.C*/
int	is_alph(char *);
int	my_strncmp(char *, char *, int);

/*CALL_ALL.C*/
void	call_arg(t_line *, char **);

/*PATH.C*/
int	choose_path(t_line *, char **);

/*BUILTINS.C*/
int	is_built(t_line *);

/*EXEC.C*/
int	launch_exec(t_line *);

/*SETENV.C*/
int	is_env(t_line *);
int	bad_setenv(t_line *);
void	do_setenv(t_line *);
int	is_setenv(t_line *);

/*UTIL_SETENV.C*/
void	ad_setenv(t_line *, t_env *, char *);
void	rep_setenv(t_line *, t_env *, char *);

/*UNSETENV.C*/
void	do_unsetenv(t_line *, t_env **);
int	is_unsetenv(t_line *);


/* /PRINT/SRC  */
int	checkflag(char c);
int	my_reader(char *buff, int fd, int j);
void	my_printf(char *str, ...);
void	my_ptab(int i, va_list ap);
void	flag_d(va_list ap);
void	flag_s(va_list ap);
void	flag_c(va_list ap);
void	my_putstr(char *);
void	my_putchar(char);
void	my_putnbr(int);
void	my_prompt(void);
void	my_sputstr(char *);
void	my_sputchar(char);

#endif	/*!_MY_H_*/
