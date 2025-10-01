/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 01:09:15 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/09 16:21:44 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newl)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
	{
		*lst = newl;
		return ;
	}
	last->next = newl;
}
