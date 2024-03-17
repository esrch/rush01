#include "checker.h"

#include <stdlib.h>

int	int_list_add(t_int_list **list, int num)
{
	t_int_list	*new_node;

	if (!list)
		return (0);
	new_node = (t_int_list *) malloc(sizeof(*new_node));
	if (!new_node)
		return (-1);
	new_node->next = NULL;
	new_node->num = num;
	if (!*list)
		*list = new_node;
	else
		int_list_last(*list)->next = new_node;
	return (0);
}

void	int_list_destroy(t_int_list *list)
{
	t_int_list	*next;

	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
}

t_int_list	*int_list_last(t_int_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

size_t	int_list_len(t_int_list *list)
{
	size_t	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int	*int_list_to_arr(t_int_list *list)
{
	int		*arr;
	size_t	len;
	size_t	i;

	if (!list)
		return (NULL);
	len = int_list_len(list);
	arr = (int *) malloc(sizeof(*arr) * (len + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (list)
	{
		arr[i] = list->num;
		i++;
		list = list->next;
	}
	arr[i] = NULL;
	return (arr);
}