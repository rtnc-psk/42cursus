/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:39:42 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/08 22:38:54 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	nbr;

	nbr = n;
	len = int_len(nbr);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	res[len--] = '\0';
	if (nbr == 0)
		res[len] = '0';
	while (nbr != 0)
	{
		res[len] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		len--;
	}
	return (res);
}
