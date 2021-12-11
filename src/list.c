/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:11:20 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/11 18:21:05 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
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

int	in_list(t_list *list, int value)
{
	while (list)
	{
		if (list->value == value)
			return (1);
		list = list->next;
	}
	return (0);
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
