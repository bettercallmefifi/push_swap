/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feel-idr <feel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:15:32 by feel-idr          #+#    #+#             */
/*   Updated: 2026/01/29 18:43:57 by feel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int value)
{
	t_node	*begin;

	begin = (t_node *)malloc(sizeof(t_node));
	if (!begin)
		return (NULL);
	begin->value = value;
	begin->next = NULL;
	return (begin);
}

void	ft_lstadd_back(t_node *lst, t_node *new)
{
	t_node	*end;

	end = lst;
	if (lst == NULL)
	{
		lst = new;
		return ;
	}
	else
	{
		while (end->next)
			end = end->next;
		end->next = new;
	}
	new->next = NULL;
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
