/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 get_next_line.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: rprasopk <rprasopk@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/10/08 19:23:11 by rprasopk		   #+#	  #+#			  */
/*	 Updated: 2025/10/08 19:23:14 by rprasopk		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *stash, char *buf);
char	*ft_get_line(char **stash);

char	*get_next_line(int fd)
{
	char		*res;
	char		*buf;
	static char	*stash[1024];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_strdup("");
	stash[fd] = ft_read_file(fd, stash[fd], buf);
	free(buf);
	if (!stash[fd] || stash[fd][0] == '\0')
		return (NULL);
	res = ft_get_line(&(stash[fd]));
	if (!stash[fd])
	{
		free(res);
		free(stash[fd]);
		return (NULL);
	}
	return (res);
}

char	*ft_read_file(int fd, char *stash, char *buf)
{
	int		byte_read;
	int		i;
	char	*temp;

	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(stash);
			return (NULL);
		}
		if (byte_read == 0 && !stash)
			return (NULL);
		buf[byte_read] = '\0';
		temp = stash;
		stash = ft_strjoin(temp, buf);
		free(temp);
		i = -1;
		while (buf[++i])
			if (buf[i] == '\n' || buf[i] == '\0')
				return (stash);
	}
	return (stash);
}

char	*ft_get_line(char **stash)
{
	int		i;
	char	*res;
	char	*temp;

	i = 0;
	while (((*stash)[i]))
	{
		if (((*stash)[i]) == '\n' || ((*stash)[i + 1]) == '\0')
			break ;
		i++;
	}
	temp = *stash;
	res = NULL;
	res = ft_substr(temp, 0, i + 1);
	if (!res)
	{
		free(stash);
		free(temp);
		free(res);
		return (NULL);
	}
	*stash = NULL;
	*stash = ft_strdup(temp + i + 1);
	free(temp);
	return (res);
}
