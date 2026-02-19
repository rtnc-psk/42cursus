/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 02:51:27 by rprasopk          #+#    #+#             */
/*   Updated: 2026/02/13 17:12:51 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (18);
	return (30);
}

void	sort_to_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	counter;
	int	chunk_size;

	counter = 0;
	chunk_size = get_chunk_size(size);
	while (*stack_a)
	{
		if ((*stack_a)->index <= counter)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			counter++;
		}
		else if ((*stack_a)->index <= counter + chunk_size)
		{
			pb(stack_a, stack_b);
			counter++;
		}
		else
			ra(stack_a);
	}
}

int	find_max_pos(t_stack *stack_b, int max_index)
{
	int	pos;

	pos = 0;
	while (stack_b)
	{
		if (stack_b->index == max_index)
			return (pos);
		pos++;
		stack_b = stack_b->next;
	}
	return (-1);
}

void	sort_back_to_a(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	max_index;
	int	max_pos;
	int	current_size;

	current_size = size;
	max_index = size - 1;
	while (*stack_b)
	{
		max_pos = find_max_pos(*stack_b, max_index);
		if (max_pos <= current_size / 2)
		{
			while ((*stack_b)->index != max_index)
				rb(stack_b);
		}
		else
		{
			while ((*stack_b)->index != max_index)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		max_index--;
		current_size--;
	}
}

void	butterfly_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_find_lstsize(*stack_a);
	sort_to_b(stack_a, stack_b, size);
	sort_back_to_a(stack_a, stack_b, size);
}
