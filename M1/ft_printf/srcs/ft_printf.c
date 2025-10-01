/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:47:22 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/17 23:36:48 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		count;

	if (!format)
		return (0);
	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format_pf(args, format[i]);
		}
		else
			count += ft_putchar_pf(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
