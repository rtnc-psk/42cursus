/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 get_next_line.h									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: rprasopk <rprasopk@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/09/30 22:27:45 by rprasopk		   #+#	  #+#			  */
/*	 Updated: 2025/09/30 22:34:26 by rprasopk		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
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
