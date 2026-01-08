/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:56:12 by rprasopk          #+#    #+#             */
/*   Updated: 2026/01/08 15:04:24 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execute_fork(char *path, char **cmd_args, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("fork failed");
	if (pid == 0)
	{
		if (execve(path, cmd_args, envp) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else
	{
		waitpid(pid, NULL, 0);
		ft_free_tab(cmd_args);
		free(path);
		return ;
	}
}
