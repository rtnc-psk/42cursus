/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:59:10 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/02 16:23:13 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = (char *)s;
	while (n > 0)
	{
		*(temp++) = 0;
		n--;
	}
}
/*
int	main(void)
{
	char test[] = "test for ft_bzero";

	printf("%s\n",test);
	ft_bzero(test, ft_strlen(test));
	printf("%s",(char *)test);
	return (0);
}
*/
