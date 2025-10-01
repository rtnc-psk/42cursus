/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphuntph <pphuntph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:51:03 by pphuntph          #+#    #+#             */
/*   Updated: 2025/09/20 13:52:12 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_pf(unsigned int n, const char type)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex_pf(n / 16, type);
		count += ft_puthex_pf(n % 16, type);
	}
	else
	{
		if (n <= 9)
			count += ft_putchar_pf(n + '0');
		else
		{
			if (type == 'x')
				count += ft_putchar_pf(n - 10 + 'a');
			if (type == 'X')
				count += ft_putchar_pf(n - 10 + 'A');
		}
	}
	return (count);
}
