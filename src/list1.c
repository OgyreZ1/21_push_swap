/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:11:20 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/16 20:30:50 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int n)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->n = n;
	node->score = 0;
	return (node);
}

void	push_back(t_list **list, int n)
{
	t_list	*curr;

	curr = *list;
	if (*list == NULL)
		*list = create_node(n);
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = create_node(n);
	}
}

void	push_front(t_list **list, int n)
{
	t_list	*elem;

	elem = create_node(n);
	if (*list == NULL)
		*list = elem;
	else
	{
		elem->next = (*list);
		(*list) = elem;
	}
}

int	list_median(t_list *list)
{
	int	m;
	int	i;

	m = list_min(list);
	i = 0;
	while (i++ < list_size(list) / 2)
		m = list_next_min(list, m);
	return (m);
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
