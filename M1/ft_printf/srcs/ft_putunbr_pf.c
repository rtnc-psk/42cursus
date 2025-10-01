/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:49:58 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/20 15:03:41 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_pf(unsigned int num)
{
	int	count;

	count = 0;
	if (!num)
	{
		count += ft_putchar_pf('0');
		return (count);
	}
	if (num < 10)
	{
		count = count + ft_putchar_pf((num % 10) + '0');
		return (count);
	}
	count = count + ft_putunbr_pf(num / 10);
	count = count + ft_putchar_pf((num % 10) + '0');
	return (count);
}
