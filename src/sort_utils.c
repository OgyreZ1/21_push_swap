/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:02:08 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/17 17:54:41 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_score(t_list *a, int elem)
{
	int	min;
	int	count;
	int	size;

	count = 0;
	size = list_size(a);
	min = list_min(a);
	if (a->n == min && elem < a->n)
		return (0);
	if (a->n > elem && last(a)->n < elem)
		return (0);
	while (a->next)
	{
		count++;
		if (a->next->n == min && elem < a->next->n)
			break ;
		if (a->n < elem && (a->next->n > elem || a->next->n == min))
			break ;
		a = a->next;
	}
	if (count > size / 2)
		count = -1 * (size - count);
	return (count);
}

int	b_score(t_list *b, int elem)
{
	int	count;
	int	size;

	count = 0;
	size = list_size(b);
	while (b)
	{
		if (b->n == elem)
			break ;
		b = b->next;
		count++;
	}
	if (count > size / 2)
		count = (-1) * (size - count);
	return (count);
}

void	score_elems(t_list *a, t_list *b)
{
	int	i;
	int	score_a;
	int	b_size;

	i = 0;
	b_size = list_size(b);
	while (b)
	{
		score_a = a_score(a, b->n);
		if (score_a < 0)
			score_a *= -1;
		if (i < b_size / 2)
			b->score = i + score_a;
		else
			b->score = (b_size - i) + score_a;
		i++;
		b = b->next;
	}
}

void	rotate(t_list **a, t_list **b, t_list *node)
{
	int	r_a;
	int	r_b;

	r_a = a_score(*a, node->n);
	r_b = b_score(*b, node->n);
	if (r_a < 0 && r_b < 0)
		while (r_a < 0 && r_b < 0 && r_a++ < 900 && r_b++ < 900)
			rrr(a, b, 1);
	else if (r_a > 0 && r_b > 0)
		while (r_a > 0 && r_b > 0 && r_a-- < 900 && r_b-- < 900)
			rr(a, b, 1);
	if (r_a < 0)
		while (r_a++)
			rra(a, 1);
	else
		while (r_a--)
			ra(a, 1);
	if (r_b < 0)
		while (r_b++)
			rrb(b, 1);
	else
		while (r_b--)
			rb(b, 1);
}

void	rotate_push(t_list **a, t_list **b)
{
	t_list	*to_push;
	t_list	*temp;

	(void)a;
	to_push = *b;
	temp = *b;
	while (temp)
	{
		if (temp->score < to_push->score)
			to_push = temp;
		temp = temp->next;
	}
	rotate(a, b, to_push);
	pa(a, b, 1);
}
