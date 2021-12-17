/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:28:47 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/17 17:52:16 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a, int print)
{
	t_list	*temp;

	if (list_size(*a) > 1)
	{
		push_back(a, (*a)->n);
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **b, int print)
{
	t_list	*temp;

	if (list_size(*b) > 1)
	{
		push_back(b, (*b)->n);
		temp = (*b)->next;
		free(*b);
		*b = temp;
	}
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **a, t_list **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		ft_putstr_fd("rr\n", 1);
}
