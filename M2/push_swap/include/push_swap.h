/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:02:54 by rprasopk          #+#    #+#             */
/*   Updated: 2026/02/13 14:25:56 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	butterfly_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a);
void	sort_fournfive(t_stack **stack_a, t_stack **stack_b);

//parser
t_stack	*parse_args(t_stack	*stack_a, int argc, char **argv);
void	index_stack(t_stack **stack);

//operations
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//utilities
t_stack	*stack_new(int nbr);
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	free_stack(t_stack **stack);
void	ft_free_tab(char **tab);
void	ft_error(t_stack **stack, char **args);
long	ft_atol(const char *str);
int		increment_count(void);
int		is_number(char *str);
int		is_dup(t_stack *stack, int n);
int		ft_find_lstsize(t_stack *lst);

//tester
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
#endif
