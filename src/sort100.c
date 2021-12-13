/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:02:08 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/13 16:33:30 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_borders(t_list **a, t_border *borders, int chunk)
{
	int		i;
	int		counter;

	i = -1;
	while (++i < 5)
	{
		if (i == 0)
			borders[i].l = list_min(*a);
		else
			borders[i].l = list_next_min(*a, borders[i - 1].r);
		borders[i].r = list_next_min(*a, borders[i].l);
		counter = 1;
		while (++counter < chunk)
			borders[i].r = list_next_min(*a, borders[i].r);
	}
}

int	t_find(t_list *a, t_border border)
{
	int	pos;

	pos = 1;
	while (a)
	{
		if (a->n >= border.l && a->n <= border.r)
			break ;
		pos++;
		a = a->next;
	}
	return (pos);
}

int	b_find(t_list *a, t_border border)
{
	int	i;
	int	pos;

	i = 1;
	while (a)
	{
		if (a->n >= border.l && a->n <= border.r)
			pos = i;
		i++;
		a = a->next;
	}
	return (pos);
}

// void	push_from(t_list **a, t_list **b, int pos)
// {
// 	int		i;
// 	t_list	*curr;

// 	i = 1;
// 	curr = 
// 	while ()
// }

void	sort_100(t_list **a, t_list **b, int chunk)
{
	t_border	bdrs[5];
	// int			i;
	int			br;

	(void)b;
	find_borders(a, bdrs, chunk);
	br = -1;
	// while (++br < 5)
	// {
	// 	i = -1;
	// 	while (++i < chunk)
	// 	{
	// 		if (t_find(*a, bdrs[br]) < list_size(*a) + 1 - b_find(*a, bdrs[br]))
	// 			push_from(a, b, t_find(*a, bdrs[br]));
	// 		else
	// 			push_from(a, b, b_find(*a, bdrs[br]));
	// 	}
	// 	printf("%d %d\n", bdrs[br].l, bdrs[br].r);
	// }
	printf("%d %d\n", bdrs[0].l, bdrs[0].r);
	printf("%d\n", t_find(*a, bdrs[0]));
	printf("%d\n", b_find(*a, bdrs[0]));
}
