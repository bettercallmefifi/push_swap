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

s_node	*ft_lstnew(int value)
{
	s_node	*begin;

	begin = (s_node *)malloc(sizeof(s_node));
	if (!begin)
		return (NULL);
	begin->value = value;
	begin->next = NULL;
	return (begin);
}

void	ft_lstadd_back(s_node *lst, s_node *new)
{
	s_node	*end;

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

void	ft_lstadd_front(s_node **lst, s_node *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
