/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:20:34 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/20 13:36:52 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int num)
{
	long	nbr;
	int		count;

	nbr = num;
	count = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		count++;
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_putnbr_pf(nbr / 10);
	nbr = nbr % 10 + 48;
	write(1, &nbr, 1);
	count++;
	return (count);
}
