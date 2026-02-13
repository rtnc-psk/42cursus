/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:30:14 by rprasopk          #+#    #+#             */
/*   Updated: 2026/02/13 00:31:50 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *stack)
{
	int	temp_value;
	int	temp_index;
	int	temp_pos;

	if (!stack || !stack->next)
		return ;
	temp_value = stack->value;
	temp_index = stack->index;
	temp_pos = stack->pos;
	stack->value = stack->next->value;
	stack->index = stack->next->index;
	stack->pos = stack->next->pos;
	stack->next->value = temp_value;
	stack->next->index = temp_index;
	stack->next->pos = temp_pos;
}

void	sa(t_stack **stack)
{
	swap(*stack);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack)
{
	swap(*stack);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1, "ss\n", 3);
}
