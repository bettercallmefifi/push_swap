/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feel-idr <feel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:39:45 by feel-idr          #+#    #+#             */
/*   Updated: 2026/02/02 20:59:29 by feel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct nodelist
{
	int	value;
	int	rank;
	struct nodelist	*next;
} s_node;

int			s_nodecount(s_node *stack);
void		ra_b(s_node **stack, char c);
s_node		*sa_b(s_node *stack, char c);
s_node		*rra_b(s_node *stack, char c);
void		pa_b(s_node **source_stack, s_node **to_stack, char c);
int			if_acending(s_node *stack);
int			ft_check_first(int argc, char **argv);
long long	ft_atoi(char *str);
int			ft_check_zero(char *str);
int			check_errors(int argc, char **argv);
int			is_repetition(s_node *stack);
void		sort_3(s_node **stack_a);
void		sort_5(s_node **stack_a, s_node **stack_b);
char		**ft_split(char *str, char c);
s_node		*ft_lstnew(int value);
void		ft_lstadd_back(s_node *lst, s_node *new);
void		ft_lstadd_front(s_node **lst, s_node *new);
int			low_ranked(s_node *stack);
void		let_sort(s_node **stack_a);
void		fill_stack_a(s_node **s_a, int argc, char **argv);
void		ft_clear(s_node **stack);
void		fill_rank(s_node *stack);
void		to_stack_a(s_node **stach_a, s_node **stack_b);
void		to_stack_b(s_node **stack_a, s_node **stack_b);
int			high_ranked(s_node *stack);
int			range(int check, int i, int current_range);
#endif