/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 22:39:26 by rprasopk          #+#    #+#             */
/*   Updated: 2026/01/08 13:42:33 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	char	*join;

	if (!str1)
		return (ft_strdup(str2));
	if (!str2)
		return (ft_strdup(str1));
	if (!str1 && !str2)
		return (NULL);
	join = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (*str1)
		join[i++] = *str1++;
	while (*str2)
		join[i++] = *str2++;
	join[i] = '\0';
	return (join);
}

/* int	main(void) */
/* { */
/* 	char *str; */
/* 	str = ft_strjoin("Skye", " Pearce"); */
/* 	printf("%s", str); */
/* 	return (0); */
/* } */
