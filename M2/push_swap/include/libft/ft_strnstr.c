/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:04:00 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/03 22:30:47 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hay;
	size_t	ndle;

	hay = 0;
	ndle = 0;
	if (needle[ndle] == '\0')
		return ((char *) haystack);
	while (haystack[hay] && hay < len)
	{
		while (haystack[hay + ndle] == needle[ndle]
			&& haystack[hay + ndle] && hay + ndle < len)
		{
			ndle++;
			if (needle[ndle] == '\0')
				return ((char *) haystack + hay);
		}
		ndle = 0;
		hay++;
	}
	return (NULL);
}
/*
int	main(int ac, char **av)
{
	if (ac > 1)
	{
		printf("%s", ft_strnstr(av[1], av[2], ft_strlen(av[1])));
	}
	return (0);
}
*/
