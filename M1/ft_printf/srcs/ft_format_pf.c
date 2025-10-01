/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:27:26 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/20 15:03:16 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_pf(va_list args, const char type)
{
	int	p_count;

	p_count = 0;
	if (type == 'c')
		p_count += ft_putchar_pf(va_arg(args, int));
	else if (type == 's')
		p_count += ft_putstr_pf(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		p_count += ft_putnbr_pf(va_arg(args, int));
	else if (type == 'u')
		p_count += ft_putunbr_pf(va_arg(args, unsigned int));
	else if (type == '%')
		p_count += ft_putchar_pf('%');
	else if (type == 'x' || type == 'X')
	{
		if (type == 'x')
			p_count += ft_puthex_pf(va_arg(args, unsigned int), type);
		else
			p_count += ft_puthex_pf(va_arg(args, unsigned int), type);
	}
	else if (type == 'p')
		p_count += ft_putptr_pf(va_arg(args, void *));
	return (p_count);
}
