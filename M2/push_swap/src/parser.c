/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:02:17 by rprasopk          #+#    #+#             */
/*   Updated: 2026/02/13 16:36:09 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*parse_args(t_stack	*stack_a, int argc, char **argv)
{
	char	**args;
	long	nb;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			ft_error(&stack_a, args);
		j = -1;
		while (args[++j])
		{
			if (!is_number(args[j]))
				ft_error(&stack_a, args);
			nb = ft_atol(args[j]);
			if ((nb > INT_MAX || nb < INT_MIN) || (is_dup(stack_a, (int)nb)))
				ft_error(&stack_a, args);
			stack_add_back(&stack_a, stack_new((int)nb));
		}
		ft_free_tab(args);
	}
	return (stack_a);
}

void	index_stack(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*current;
	int		count;

	current = *stack;
	while (current)
	{
		ptr = *stack;
		count = 0;
		while (ptr)
		{
			if (ptr->value < current->value)
				count++;
			ptr = ptr->next;
		}
		current->index = count;
		current = current->next;
	}
}
