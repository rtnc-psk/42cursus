/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 get_next_line_utils.c								:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: rprasopk <rprasopk@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/09/30 22:27:38 by rprasopk		   #+#	  #+#			  */
/*	 Updated: 2025/09/30 22:35:42 by rprasopk		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(char *str)
{
	ssize_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

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

char	*ft_strdup(char *str)
{
	char	*res;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	res = malloc(ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char *str, int start, int end)
{
	int		len;
	char	*res;
	int		i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (start > len)
		return (ft_strdup(""));
	if ((start + end) > len)
		end = len - start;
	res = malloc(end + 1);
	if (!res)
		return (NULL);
	i = 0;
	res[end] = '\0';
	while (start < end)
	{
		res[i] = str[start];
		i++;
		start++;
	}
	return (res);
}

void	*ft_strchr(char *s, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char) c;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}
