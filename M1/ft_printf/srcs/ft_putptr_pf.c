/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:09:50 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/20 13:22:21 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putultoh(unsigned long vptr)
{
	int					count;
	unsigned long long	ull;

	count = 0;
	ull = (unsigned long long)vptr;
	if (ull >= 16)
	{
		count = count + ft_putultoh(ull / 16);
		count = count + ft_putultoh(ull % 16);
	}
	else
	{
		if (ull <= 9)
			count = count + ft_putchar_pf(ull + '0');
		else
			count = count + ft_putchar_pf(ull - 10 + 'a');
	}
	return (count);
}

int	ft_putptr_pf(void *ptr)
{
	int				count;
	unsigned long	vptr;

	count = 0;
	if (!ptr)
		return (count = count + ft_putstr_pf("(nil)"));
	vptr = (unsigned long)ptr;
	count = count + ft_putstr_pf("0x");
	count = count + ft_putultoh(vptr);
	return (count);
}
