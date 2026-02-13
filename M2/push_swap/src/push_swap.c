/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:28:38 by rprasopk          #+#    #+#             */
/*   Updated: 2026/02/13 16:36:28 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc < 2 || argv[1][0] == '\0')
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = parse_args(stack_a, argc, argv);
	index_stack(&stack_a);
	size = ft_find_lstsize(stack_a);
	if (size == 2)
	{
		if (stack_a->index > stack_a->next->index)
			sa(&stack_a);
	}
	else if (size == 3)
		sort_three(&stack_a);
	else if (size <= 5)
		sort_fournfive(&stack_a, &stack_b);
	else
		butterfly_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
