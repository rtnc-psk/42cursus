/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:50:48 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/20 15:03:54 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!s)
	{
		count += ft_putstr_pf("(null)");
		return (count);
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], 1);
		count++;
		i++;
	}
	return (count);
}
