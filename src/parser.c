/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:53:33 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/12 13:46:03 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_list(t_list *list, int value)
{
	while (list)
	{
		if (list->value == value)
			return (1);
		list = list->next;
	}
	return (0);
}

int	is_integer(char *s)
{
	size_t	i;

	i = -1;
	if (ft_strlen(s) == 0)
		return (0);
	if (s[0] == '-' && ft_strlen(s) > 1)
		i = 0;
	while (++i < ft_strlen(s))
	{
		if (!ft_isdigit(s[i]))
			return (0);
	}
	if (ft_strlen(s) > 11)
		return (0);
	if (s[0] != '-' && ft_strlen(s) == 10 && ft_atoi(s) <= 0)
		return (0);
	if (s[0] == '-' && ft_strlen(s) == 11 && ft_atoi(s) >= 0)
		return (0);
	return (1);
}

void	fill_a(t_list **a, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (is_integer(argv[i]) && !in_list(*a, ft_atoi(argv[i])))
			push_back(a, ft_atoi(argv[i]));
		else
		{
			ft_putstr_fd("Error\n", 2);
			free_list(a);
			exit(-1);
		}
	}
}
