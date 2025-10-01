/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:29:30 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/02 16:44:54 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_temp;
	unsigned char	*src_temp;

	if (src == (void *)0 && dst == (void *)0)
	{
		return (dst);
	}
	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char *)src;
	while (n > 0)
	{
		*(dst_temp++) = *(src_temp++);
		n--;
	}
	return (dst);
}
/*
int	main(void)
{
	char str1[] = "test for ft_memcpy";
	char str2[] = "try to cpy to this str";

	printf("%s\n%s\n", str1, str2);
	printf("\n%s", (char *)ft_memcpy(str2, str1, ft_strlen(str1)));
	return (0);
}
*/
