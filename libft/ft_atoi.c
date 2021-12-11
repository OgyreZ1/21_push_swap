/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:59:31 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/11 17:37:20 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\f' || \
	c == '\t' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	ans;
	int	i;
	int	sign;

	ans = 0;
	i = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		ans *= 10;
		ans += str[i] - 48;
		i++;
	}
	return (sign * ans);
}
