/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:14:25 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/17 17:54:30 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **a)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = (*a)->n;
	a2 = (*a)->next->n;
	a3 = (*a)->next->next->n;
	if (a1 > a2 && a1 < a3)
		sa(a, 1);
	else if (a1 < a2 && a1 > a3)
		rra(a, 1);
	else if (a3 > a1 && a3 < a2)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if (a2 < a1 && a2 > a3)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (a3 < a1 && a3 > a2)
		ra(a, 1);
}

void	pb_min(t_list **a, t_list **b)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *a;
	while (temp)
	{
		if (temp->n == list_min(*a))
			break ;
		i++;
		temp = temp->next;
	}
	if (i > list_size(*a) / 2)
		while (i++ < 5)
			rra(a, 1);
	else
		while (i--)
			ra(a, 1);
	pb(a, b, 1);
}

void	sort_5(t_list **a, t_list **b)
{
	int		i;

	pb_min(a, b);
	i = 0;
	if ((*a)->next->n == list_max(*a))
		ra(a, 1);
	else if ((*a)->next->next->n == list_max(*a))
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (last(*a)->n == list_max(*a))
		rra(a, 1);
	pb(a, b, 1);
	sort_3(a);
	pa(a, b, 1);
	ra(a, 1);
	pa(a, b, 1);
}

void	last_rotates(t_list **a)
{
	int		min_pos;
	t_list	*temp;

	min_pos = 0;
	temp = *a;
	while (temp)
	{
		if (temp->n == list_min(*a))
			break ;
		temp = temp->next;
		min_pos++;
	}
	if (min_pos > list_size(*a) / 2)
		min_pos = min_pos - list_size(*a);
	if (min_pos > 0)
		while (min_pos--)
			ra(a, 1);
	else
		while (min_pos++)
			rra(a, 1);
}

void	sort_100(t_list **a, t_list **b)
{
	int	m;

	m = list_median(*a);
	while (list_size(*a) > 2)
	{
		if ((*a)->n == list_min(*a) || (*a)->n == list_max(*a))
			ra(a, 1);
		if ((*a)->n < m)
			pb(a, b, 1);
		else
		{
			pb(a, b, 1);
			rb(b, 1);
		}
	}
	if (!is_sorted(*a))
		ra(a, 1);
	while (list_size(*b) > 0)
	{
		score_elems(*a, *b);
		rotate_push(a, b);
	}
	last_rotates(a);
}
