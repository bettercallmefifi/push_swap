/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feel-idr <feel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:16:05 by feel-idr          #+#    #+#             */
/*   Updated: 2026/01/30 15:44:13 by feel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	s_nodecount(s_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	ra_b(s_node **stack, char c)
{
	s_node	*tmp;
	s_node	*to_end;

	to_end = *stack;
	tmp = (*stack)->next;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = to_end;
	to_end->next = NULL;
	*stack = tmp;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

s_node	*rra_b(s_node *stack, char c)
{
	s_node	*to_first;
	s_node	*pre;

	to_first = stack;
	while (to_first->next)
	{
		pre = to_first;
		to_first = to_first->next;
	}
	pre->next = NULL;
	to_first->next = stack;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	return (to_first);
}

s_node	*sa_b(s_node *stack, char c)
{
	s_node	*second;
	int		i;

	i = 1;
	second = stack;
	while (i++ < 2)
		second = second->next;
	stack->next = second->next;
	second->next = stack;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	return (second);
}

void	pa_b(s_node **source_stack, s_node **tostack, char c)
{
	s_node	*tmp;
	s_node	*prev;

	prev = *source_stack;
	tmp = (*source_stack)->next;
	if (!(*tostack))
	{
		*tostack = prev;
		(*tostack)->next = NULL;
		*source_stack = tmp;
	}
	else
	{
		ft_lstadd_front(tostack, prev);
		*source_stack = tmp;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}
