/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:53:38 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/18 15:49:27 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_list
{
	int				n;
	int				score;
	struct s_list	*next;
}				t_list;

void	fill_a(t_list **a, int argc, char **argv);
t_list	*create_node(int n);
void	push_back(t_list **list, int n);
void	push_front(t_list **list, int n);
int		list_size(t_list *list);
void	free_list(t_list **list);
int		is_sorted(t_list *list);
t_list	*last(t_list *list);
int		list_min(t_list *list);
int		list_median(t_list *list);
int		list_max(t_list *list);
int		list_next_min(t_list *list, int min);

void	sort_3(t_list **a);
void	roll_push_roll(t_list **a, t_list **b);
void	sort_5(t_list **a, t_list **b);
void	sort_100(t_list **a, t_list **b);

void	score_elems(t_list *a, t_list *b);
void	rotate_push(t_list **a, t_list **b);

void	sa(t_list **a, int print);
void	sb(t_list **b, int print);
void	ss(t_list **a, t_list **b, int print);
void	pb(t_list **a, t_list **b, int print);
void	pa(t_list **a, t_list **b, int print);
void	ra(t_list **a, int print);
void	rb(t_list **b, int print);
void	rr(t_list **a, t_list **b, int print);
void	rra(t_list **a, int print);
void	rrb(t_list **b, int print);
void	rrr(t_list **a, t_list **b, int print);

#endif