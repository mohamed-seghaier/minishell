/*
** EPITECH PROJECT, 2018
** list
** File description:
** Outils list
*/

#include "../include/my.h"

t_env	*add_node(t_env *head, char *str)
{
	t_env	*elem = malloc(sizeof(t_env));

	if (!elem)
		return (NULL);
	elem->str = str;
	elem->next = NULL;
	if (!head)
		return (elem);
	t_env	*tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
	return (head);
}

void	print_list(t_env *head)
{
	t_env	*tmp = head;

	while (tmp) {
		my_printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
}

int	list_length(t_env *head)
{
	int	a = 0;
	t_env	*tmp = head;

	if (tmp == NULL)
		return (0);
	while (tmp != NULL) {
	        a += 1;
		tmp = tmp->next;
	}
	return (a);
}

int	erase_node(t_env **head, int index)
{
	t_env	*a = *head;
	t_env	*b = NULL;
	int	j = 0;

	if (index == 0 || index > list_length(*head))
		return (-1);
	if (index == 1) {
		(*head) = (*head)->next;
		return (0);
	}
	while (++j < index - 1) {
		a = a->next;
	}
	b = a->next;
	a->next = b->next;
	return (0);
}
