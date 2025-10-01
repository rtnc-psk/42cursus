/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_atoi.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: rprasopk <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/09/04 22:54:14 by rprasopk		   #+#	  #+#			  */
/*	 Updated: 2025/09/06 05:31:43 by rprasopk		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}

int	ft_atoi(const char *str)
{
	int	r;
	int	pn;

	r = 0;
	pn = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		pn = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		r = r * 10 + *str++ - '0';
	return (r * pn);
}

/* #include <stdio.h> */

/* int	main(void) */
/* { */
/*	printf("%d", ft_atoi("0")); */
/* } */
