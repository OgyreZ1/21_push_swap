/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:11:20 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/12 13:47:21 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->value = value;
	return (node);
}

void	push_back(t_list **list, int value)
{
	t_list	*curr;

	curr = *list;
	if (*list == NULL)
		*list = create_node(value);
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = create_node(value);
	}
}

void	push_front(t_list **list, int value)
{
	t_list	*elem;

	elem = create_node(value);
	if (*list == NULL)
		*list = elem;
	else
	{
		elem->next = (*list);
		(*list) = elem;
	}
}

void	free_list(t_list **list)
{
	t_list	*curr;
	t_list	*temp;

	curr = *list;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
}

int	list_size(t_list *list)
{
	int	c;

	c = 0;
	while (list)
	{
		c++;
		list = list->next;
	}
	return (c);
}
