/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feel-idr <feel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:39:36 by feel-idr          #+#    #+#             */
/*   Updated: 2026/01/30 15:49:13 by feel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
		tmp = NULL;
	}
}

void	fill_stack_a(t_node **s_a, int argc, char **argv)
{
	char	**numstr;
	int		i;
	int		j;
	int		k;

	i = 1;
	while (i < argc)
	{
		numstr = ft_split(argv[i], ' ');
		j = 0;
		while (numstr[j])
		{
			if (i == 1 && j == 0)
				*s_a = ft_lstnew(ft_atoi(numstr[j]));
			else
				ft_lstadd_back(*s_a, ft_lstnew(ft_atoi(numstr[j])));
			j++;
		}
		k = 0;
		while (numstr[k])
			free(numstr[k++]);
		free(numstr);
		numstr = NULL;
		i++;
	}
}

void	let_sort(t_node **stack_a)
{
	t_node	*stack_b;

	stack_b = NULL;
	if (t_nodecount(*stack_a) == 3)
		sort_3(stack_a);
	else if (t_nodecount(*stack_a) == 5)
		sort_5(stack_a, &stack_b);
	else
	{
		to_stack_b(stack_a, &stack_b);
		to_stack_a(stack_a, &stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (check_errors(argc, argv) == 0)
		return (0);
	fill_stack_a(&stack_a, argc, argv);
	if (is_repetition(stack_a))
	{
		ft_clear(&stack_a);
		write(2, "Error\n", 6);
		return (0);
	}
	if (if_acending(stack_a))
	{
		ft_clear(&stack_a);
		return (0);
	}
	let_sort(&stack_a);
	ft_clear(&stack_a);
	stack_a = NULL;
	return (0);
}
