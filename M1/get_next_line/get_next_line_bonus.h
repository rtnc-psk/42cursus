/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 03:43:39 by rprasopk          #+#    #+#             */
/*   Updated: 2025/10/15 03:47:20 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *stash, char *buf);
char	*ft_get_line(char **stash);

char	*ft_substr(char *str, int start, int end);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strdup(char *str);
char	*ft_free(char **ptr);
ssize_t	ft_strlen(char *str);

#endif
