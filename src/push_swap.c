/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:55:58 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/12 13:24:46 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%d ", list->value);
		list = list->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (argc == 1)
		exit(0);
	fill_a(&a, argc, argv);
	sa(&a, 1);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	ra(&a, 1);
	rb(&b, 1);
	rra(&a, 1);
	rrb(&b, 1);
	sa(&a, 1);
	pa(&a, &b);
	pa(&a, &b);
	pa(&a, &b);
	print_list(a);
}
