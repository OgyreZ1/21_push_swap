/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:55:58 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/17 17:53:59 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **a, t_list **b)
{
	(void)b;
	if (is_sorted(*a))
		return ;
	if (list_size(*a) == 2)
		sa(a, 1);
	else if (list_size(*a) == 3)
		sort_3(a);
	else if (list_size(*a) <= 5)
		sort_5(a, b);
	else
		sort_100(a, b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (argc == 1)
		exit(0);
	fill_a(&a, argc, argv);
	sort(&a, &b);
	free_list(&a);
	free_list(&b);
}
