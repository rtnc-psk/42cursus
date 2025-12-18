/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:29:35 by rprasopk          #+#    #+#             */
/*   Updated: 2025/12/19 00:17:20 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_process(int *fd, char **arv, char **envp);
void	parent_process(int *fd, char **arv, char **envp);
void	execute_cmd(char *arv, char **envp);
char	*find_path(char *cmd, char **envp);
void	ft_free_tab(char **tab);

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
		return (-1);
	if (pid == 0)
		child_process(fd, arv, envp);
	else
	{
		waitpid(pid, NULL, 0);
		parent_process(fd, arv, envp);
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
		perror("Command not fond");
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
	if (execve(path, cmd_args, envp) == -1)
	{
		perror("execve");
		exit(1);
	}
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*part_path;
	char	*full_path;
	int		i;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
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

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
