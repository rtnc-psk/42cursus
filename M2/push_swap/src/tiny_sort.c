/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:08:05 by rprasopk          #+#    #+#             */
/*   Updated: 2026/02/13 17:14:09 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	sort_three(t_stack **stack_a)
{
	t_stack	*head;
	int		max_index;

	max_index = find_max_index(*stack_a);
	head = *stack_a;
	if (head->index == max_index)
		ra(stack_a);
	else if (head->next->index == max_index)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

static int	get_min_pos(t_stack *stack, int val)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == val)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

void	sort_fournfive(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	min_pos;
	int	target_index;

	target_index = 0;
	size = ft_find_lstsize(*stack_a);
	while (size > 3)
	{
		min_pos = get_min_pos(*stack_a, target_index);
		if (min_pos <= size / 2)
			while ((*stack_a)->index != target_index)
				ra(stack_a);
		else
			while ((*stack_a)->index != target_index)
				rra(stack_a);
		pb(stack_a, stack_b);
		target_index++;
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
