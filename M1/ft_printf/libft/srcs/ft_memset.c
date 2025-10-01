/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:40:32 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/02 15:54:00 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *) str;
	while (len > 0)
	{
		*(temp++) = (unsigned char) c;
		len--;
	}
	return (str);
}

/*
int	main(void)
{
	char test[] = "test for ft_memset";

	printf("%s", (char *)ft_memset(test, 'x', ft_strlen(test)));
	return (0);
}
*/
