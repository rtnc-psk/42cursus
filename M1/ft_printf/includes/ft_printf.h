/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:19:59 by rprasopk          #+#    #+#             */
/*   Updated: 2025/09/17 23:40:50 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_format_pf(va_list args, const char type);
int	ft_putchar_pf(int c);
int	ft_putstr_pf(char *s);
int	ft_putptr_pf(void *ptr);
int	ft_putnbr_pf(int num);
int	ft_putunbr_pf(unsigned int num);
int	ft_puthex_pf(unsigned int n, const char type);

#endif
