/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feel-idr <feel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:56:54 by feel-idr          #+#    #+#             */
/*   Updated: 2026/01/27 21:59:25 by feel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_first(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!(argv[i][0] >= '0' && argv[i][0] <= '9')
			&& !(argv[i][0] == '-' || argv[i][0] == '+'))
			return (0);
		i++;
	}
	return (1);
}

long long	ft_atoi(char *str)
{
	long long	result;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		if (!(str[i] >= '0' && str[i] <= '9') && !(str[i] == ' '))
			return (0);
		i++;
	}
	return (sign * result);
}

int	ft_check_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	check_errors(int argc, char **argv)
{
	int	i;

	if (ft_check_first(argc, argv) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (!ft_atoi(argv[i]) && ft_check_zero(argv[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_repetition(s_node *stack)
{
	s_node	*first;
	int		data;

	while (stack)
	{
		data = stack->value;
		first = stack->next;
		while (first)
		{
			if (data == first->value)
				return (1);
			first = first->next;
		}
		stack = stack->next;
	}
	return (0);
}
