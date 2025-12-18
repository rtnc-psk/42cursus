/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:32:15 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/05 15:58:02 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	while (i < count * size)
		temp[i++] = 0;
	return (temp);
}
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count * size > INT_MAX || count > INT_MAX || size > INT_MAX)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset((unsigned char *) ptr, 0, count * size);
	return (ptr);
}
