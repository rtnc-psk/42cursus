/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <miarvin@42.fr>                    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 00:30:35 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/08 21:51:59 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strrchr(set, s1[j]))
		j--;
	return (ft_substr(s1, i, j - (i - 1)));
}
/*
int	main(void)
{
	char	str[] = "baababaMy name is Simonbaabab";
	printf("%s\n%s", str, ft_strtrim(str, "ab"));
	return (0);
}
*/
