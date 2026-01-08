/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:29:35 by rprasopk          #+#    #+#             */
/*   Updated: 2026/01/08 15:08:24 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_process(int *fd, char **arv, char **envp);
void	parent_process(int *fd, char **arv, char **envp);
void	execute_cmd(char *arv, char **envp);
char	*find_path(char *cmd, char **envp);

int	main(int arc, char **arv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (arc != 5)
		return (1);
	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return (-1);
	}
	if (pid == 0)
		child_process(fd, arv, envp);
	else
	{
		parent_process(fd, arv, envp);
		waitpid(pid, NULL, 0);
	}
}

void	child_process(int *fd, char **arv, char **envp)
{
	int	infile;

	infile = open(arv[1], O_RDONLY);
	if (infile == -1)
	{
		perror("infile open failed");
		exit(1);
	}
	dup2(fd[1], 1);
	dup2(infile, 0);
	close(fd[0]);
	close(fd[1]);
	close(infile);
	execute_cmd(arv[2], envp);
}

void	parent_process(int *fd, char **arv, char **envp)
{
	int	outfile;

	outfile = open(arv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		perror("outfile open failed");
		exit(1);
	}
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[1]);
	close(fd[0]);
	close(outfile);
	execute_cmd(arv[3], envp);
}

void	execute_cmd(char *arv, char **envp)
{
	char	**cmd_args;
	char	*path;

	if (!arv[0])
	{
		perror("Command not found");
		exit(127);
	}
	cmd_args = ft_split(arv, ' ');
	if (!cmd_args)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	path = find_path(cmd_args[0], envp);
	if (!path)
	{
		ft_free_tab(cmd_args);
		perror("Command not found");
		exit(127);
	}
	execute_fork(path, cmd_args, envp);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*part_path;
	char	*full_path;
	int		i;

	if (ft_strchr(cmd, '/'))
		return (cmd_check(cmd));
	paths = find_envp(envp);
	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(full_path, F_OK) == 0)
		{
			ft_free_tab(paths);
			return (full_path);
		}
		free(full_path);
	}
	ft_free_tab(paths);
	return (NULL);
}
