/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:14:22 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/03 18:29:45 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *) s1;
	ss2 = (unsigned char *) s2;
	while (i < n)
	{
		if ((unsigned char) ss1[i] != (unsigned char) ss2[i])
			return ((unsigned char) ss1[i] - (unsigned char) ss2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char s1[] = "testzfor memcmp";
	char s2[] = "testxfor memcmp";

	printf("%d", ft_memcmp(s1, s2, 6));
	return (0);
}
*/
