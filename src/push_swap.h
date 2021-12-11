/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:53:38 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/11 18:44:27 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}				t_list;

void	fill_a(t_list **a, int argc, char **argv);
void	push_back(t_list **list, int value);
void	push_front(t_list **list, int value);
int		in_list(t_list *list, int value);
int		list_size(t_list *list);

void	sa(t_list **a, int print);
void	sb(t_list **b, int print);
void	ss(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	ra(t_list **a, int print);
void	rb(t_list **b, int print);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a, int print);
void	rrb(t_list **b, int print);
void	rrr(t_list **a, t_list **b);

#endif