/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_acending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feel-idr <feel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:00:45 by feel-idr          #+#    #+#             */
/*   Updated: 2026/01/27 22:02:45 by feel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_acending(s_node *stack)
{
	s_node	*comp;

	comp = stack->next;
	while (comp)
	{
		if (comp->value < stack->value)
			return (0);
		stack = stack->next;
		comp = stack->next;
	}
	return (1);
}
