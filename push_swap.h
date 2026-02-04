/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feel-idr <feel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:39:45 by feel-idr          #+#    #+#             */
/*   Updated: 2026/01/30 15:48:48 by feel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct nodelist
{
	int				value;
	int				rank;
	struct nodelist	*next;
}	t_node;

int			t_nodecount(t_node *stack);
void		ra_b(t_node **stack, char c);
t_node		*sa_b(t_node *stack, char c);
t_node		*rra_b(t_node *stack, char c);
void		pa_b(t_node **source_stack, t_node **to_stack, char c);
int			if_acending(t_node *stack);
int			ft_check_first(int argc, char **argv);
long long	ft_atoi(char *str);
int			ft_check_zero(char *str);
int			check_errors(int argc, char **argv);
int			is_repetition(t_node *stack);
void		sort_3(t_node **stack_a);
void		sort_5(t_node **stack_a, t_node **stack_b);
char		**ft_split(char *str, char c);
t_node		*ft_lstnew(int value);
void		ft_lstadd_back(t_node *lst, t_node *new);
void		ft_lstadd_front(t_node **lst, t_node *new);
int			low_ranked(t_node *stack);
void		let_sort(t_node **stack_a);
void		fill_stack_a(t_node **s_a, int argc, char **argv);
void		ft_clear(t_node **stack);
void		to_stack_a(t_node **stach_a, t_node **stack_b);
void		to_stack_b(t_node **stack_a, t_node **stack_b);
int			high_ranked(t_node *stack);
void		fill_rank(t_node *stack);

#endif