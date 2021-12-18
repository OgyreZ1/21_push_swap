/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:31:04 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/18 15:28:27 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_exit(t_list **a, t_list **b, char *cmd, int flag)
{
	if (flag == -1)
		ft_putstr_fd("Error\n", 2);
	else if (flag == 0)
		ft_putstr_fd("OK\n", 1);
	else if (flag == 1)
		ft_putstr_fd("KO\n", 1);
	free_list(a);
	free_list(b);
	free(cmd);
	exit(0);
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
		free_exit(a, b, cmd, -1);
}

void	read_cmd(char **cmd)
{
	int		rd;
	int		i;

	rd = 0;
	i = 0;
	rd = read(0, &(*cmd)[i], 1);
	while (rd > 0 && (*cmd)[i] != '\n')
	{
		i++;
		rd = read(0, &(*cmd)[i], 1);
	}
	(*cmd)[i] = '\0';
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*cmd;

	b = NULL;
	cmd = malloc(1000000);
	if (argc == 1)
		exit(0);
	fill_a(&a, argc, argv);
	if (is_sorted(a))
		free_exit(&a, &b, cmd, 0);
	while (1)
	{
		read_cmd(&cmd);
		if (ft_strlen(cmd) == 0)
			break ;
		execute(&a, &b, cmd);
	}
	if (is_sorted(a) && list_size(b) == 0)
		free_exit(&a, &b, cmd, 0);
	else
		free_exit(&a, &b, cmd, 1);
}
