/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feel-idr <feel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:20:07 by feel-idr          #+#    #+#             */
/*   Updated: 2026/02/02 20:58:30 by feel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	high_ranked(t_node *stack)
{
	int	count;
	int	i;
	int	high;

	i = 1;
	count = 1;
	high = stack->value;
	while (stack)
	{
		if (high < stack->value)
		{
			count = i;
			high = stack->value;
		}
		i++;
		stack = stack->next;
	}
	return (count);
}

int	low_ranked(t_node *stack)
{
	int	i;
	int	count;
	int	high;

	i = 1;
	count = 1;
	high = stack->value;
	while (stack)
	{
		if (high > stack->value)
		{
			count = i;
			high = stack->value;
		}
		stack = stack->next;
		i++;
	}
	return (count);
}

int	*to_array(t_node *stack_a)
{
	int	*arr;
	int	i;

	arr = malloc(t_nodecount(stack_a) * sizeof(stack_a));
	i = 0;
	while (stack_a)
	{
		arr[i] = stack_a->value;
		stack_a = stack_a->next;
		i++;
	}
	return (arr);
}

int	*arr_stored(int n, t_node *stack)
{
	int	*arr;
	int	tmp;
	int	i;
	int	j;

	arr = to_array(stack);
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	fill_rank(t_node *stack)
{
	int	*arr;
	int	i;
	int	count;

	count = t_nodecount(stack);
	arr = arr_stored(count, stack);
	while (stack)
	{
		i = 0;
		while (i < count)
		{
			if (arr[i] == stack->value)
				stack->rank = i + 1;
			i++;
		}
		stack = stack->next;
	}
	free(arr);
	arr = NULL;
}
