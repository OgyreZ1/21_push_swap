/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:38:15 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/12 17:14:21 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a, int print)
{
	t_list	*prev;
	t_list	*curr;

	if (list_size(*a) > 1)
	{
		curr = *a;
		prev = NULL;
		while (curr->next)
		{
			prev = curr;
			curr = curr->next;
		}
		push_front(a, curr->n);
		free(prev->next);
		prev->next = NULL;
	}
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **b, int print)
{
	t_list	*prev;
	t_list	*curr;

	if (list_size(*b) > 1)
	{
		curr = *b;
		prev = NULL;
		while (curr->next)
		{
			prev = curr;
			curr = curr->next;
		}
		push_front(b, curr->n);
		free(prev->next);
		prev->next = NULL;
	}
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_putstr_fd("rrr\n", 1);
}
