/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feel-idr <feel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:18:19 by feel-idr          #+#    #+#             */
/*   Updated: 2026/02/02 21:15:39 by feel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	range(int check, int i, int current_range)
{
	int	max;

	if (check)
		max = i + 35;
	else
		max = i + 15;
	if (current_range >= i && current_range < max)
		return (0);
	else if (current_range < i)
		return (-1);
	else
		return (1);
}

void	to_stack_b(s_node **stack_a, s_node **stack_b)
{
	int	i;
	int	check;

	fill_rank(*stack_a);
	if (s_nodecount(*stack_a) >= 500)
		check = 1;
	else
		check = 0;
	i = 1;
	while (*stack_a)
	{
		if (range(check, i, (*stack_a)->rank) == 0)
		{
			pa_b(stack_a, stack_b, 'b');
			i++;
		}
		else if (range(check, i, (*stack_a)->rank) == -1)
		{
			pa_b(stack_a, stack_b, 'b');
			ra_b(stack_b, 'b');
			i++;
		}
		else
			ra_b(stack_a, 'a');
	}
}

void	to_stack_a(s_node **stack_a, s_node **stack_b)
{
	int	rank;
	
	while (s_nodecount(*stack_b))
	{
		rank = high_ranked(*stack_b);
		if (rank == 1 || rank <= s_nodecount(*stack_b) / 2)
		{
			while (rank-- > 1)
				ra_b(stack_b, 'b');
			pa_b(stack_b, stack_a, 'a');
		}
		else
		{
			while (rank++ <= s_nodecount(*stack_b))
				*stack_b = rra_b(*stack_b, 'b');
			pa_b(stack_b, stack_a, 'a');
		}
	}
}

void	sort_3(s_node **stack_a)
{
	while (!if_acending(*stack_a))
	{
		if ((*stack_a)->value > (*stack_a)->next->value
			&& (*stack_a)->value < (*stack_a)->next->next->value)
			*stack_a = sa_b(*stack_a, 'a');
		else if ((*stack_a)->value > (*stack_a)->next->value
			&& (*stack_a)->value > (*stack_a)->next->next->value)
			ra_b(stack_a, 'a');
		else
			*stack_a = rra_b(*stack_a, 'a');
	}
}

void	sort_5(s_node **stack_a, s_node **stack_b)
{
	int	rank;
	int	i;
	int	two;

	two = 1;
	while (two++ < 3)
	{
		rank = low_ranked(*stack_a);
		i = rank;
		if (rank <= 3)
		{
			while (i-- > 1)
				ra_b(stack_a, 'a');
			pa_b(stack_a, stack_b, 'b');
		}
		else
		{
			while (i++ <= s_nodecount(*stack_a))
				*stack_a = rra_b(*stack_a, 'a');
			pa_b(stack_a, stack_b, 'b');
		}
	}
	sort_3(stack_a);
	pa_b(stack_b, stack_a, 'a');
	pa_b(stack_b, stack_a, 'a');
}
