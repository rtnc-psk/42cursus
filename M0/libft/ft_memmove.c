/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 04:42:10 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/06 05:10:56 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*srctemp;
	unsigned char	*dsttemp;

	srctemp = (unsigned char *) src;
	dsttemp = (unsigned char *) dst;
	if (!dst && !src)
		return (dst);
	if (srctemp < dsttemp)
		while (len--)
			dsttemp[len] = srctemp[len];
	else
		while (len--)
			*dsttemp++ = *srctemp++;
	return (dst);
}
