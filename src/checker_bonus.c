/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:31:04 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/17 18:21:00 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *cmd)
{
	free(cmd);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

void	execute(t_list **a, t_list **b, char *cmd)
{
	if (ft_strlen(cmd) == 2 && ft_strncmp(cmd, "sa", 2) == 0)
		sa(a, 0);
	else if (ft_strlen(cmd) == 2 && ft_strncmp(cmd, "sb", 2) == 0)
		sb(b, 0);
	else if (ft_strlen(cmd) == 2 && ft_strncmp(cmd, "ss", 2) == 0)
		ss(a, b, 0);
	else if (ft_strlen(cmd) == 2 && ft_strncmp(cmd, "pa", 2) == 0)
		pa(a, b, 0);
	else if (ft_strlen(cmd) == 2 && ft_strncmp(cmd, "pb", 2) == 0)
		pb(a, b, 0);
	else if (ft_strlen(cmd) == 2 && ft_strncmp(cmd, "ra", 2) == 0)
		ra(a, 0);
	else if (ft_strlen(cmd) == 2 && ft_strncmp(cmd, "rb", 2) == 0)
		rb(a, 0);
	else if (ft_strlen(cmd) == 2 && ft_strncmp(cmd, "rr", 2) == 0)
		rr(a, b, 0);
	else if (ft_strlen(cmd) == 3 && ft_strncmp(cmd, "rra", 3) == 0)
		rra(a, 0);
	else if (ft_strlen(cmd) == 3 && ft_strncmp(cmd, "rrb", 3) == 0)
		rrb(a, 0);
	else if (ft_strlen(cmd) == 3 && ft_strncmp(cmd, "rrr", 3) == 0)
		rrr(a, b, 0);
	else
		error(cmd);
}

void	read_cmd(char **cmd)
{
	int		rd;
	int		i;
	char	*buff;

	rd = 0;
	i = 0;
	buff = malloc(100000);
	*cmd = buff;
	rd = read(0, &buff[i], 1);
	while (rd > 0 && buff[i] != '\n')
	{
		i++;
		rd = read(0, &buff[i], 1);
	}
	buff[i] = '\0';
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*cmd;

	b = NULL;
	if (argc == 1)
		exit(0);
	fill_a(&a, argc, argv);
	if (is_sorted(a))
	{
		ft_putstr_fd("OK\n", 1);
		exit(0);
	}
	while (1)
	{
		read_cmd(&cmd);
		if (ft_strlen(cmd) == 0)
			break ;
		execute(&a, &b, cmd);
	}
	free(cmd);
	if (is_sorted(a) && list_size(b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 2);
}
