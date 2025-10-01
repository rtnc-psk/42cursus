/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 22:39:26 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/06 00:13:57 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	temp = malloc(s1_len + s2_len * sizeof(char) + 1);
	if (!temp)
		return (NULL);
	while (++i < s1_len)
		temp[i] = s1[i];
	while (i < (s1_len + s2_len))
		temp[i++] = s2[j++];
	temp[i] = '\0';
	return (temp);
}

/* int	main(void) */
/* { */
/* 	char *str; */
/* 	str = ft_strjoin("Skye", " Pearce"); */
/* 	printf("%s", str); */
/* 	return (0); */
/* } */
