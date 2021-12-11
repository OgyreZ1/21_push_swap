/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:03:41 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/11 18:27:02 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a, int print)
{
	t_list	*temp;

	if (list_size(*a) >= 2)
	{
		temp = (*a)->next;
		(*a)->next = temp->next;
		temp->next = *a;
		*a = temp;
	}
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **b, int print)
{
	t_list	*temp;

	if (list_size(*b) >= 2)
	{
		temp = (*b)->next;
		(*b)->next = temp->next;
		temp->next = *b;
		*b = temp;
	}
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **a, t_list **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_list **a, t_list **b)
{
	if (list_size(*b) > 0)
	{
		push_front(a, (*b)->value);
		*b = (*b)->next;
	}
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **a, t_list **b)
{
	if (list_size(*a) > 0)
	{
		push_front(b, (*a)->value);
		*a = (*a)->next;
	}
	ft_putstr_fd("pb\n", 1);
}
