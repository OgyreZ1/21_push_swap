/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:47:11 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/12 17:14:30 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *list)
{
	while (list->next)
	{
		if (list->next->n < list->n)
			return (0);
		list = list->next;
	}
	return (1);
}

t_list	*last(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	list_min(t_list *list)
{
	int	min;

	min = list->n;
	while (list)
	{
		if (list->n < min)
			min = list->n;
		list = list->next;
	}
	return (min);
}

int	list_max(t_list *list)
{
	int	max;

	max = list->n;
	while (list)
	{
		if (list->n > max)
			max = list->n;
		list = list->next;
	}
	return (max);
}
