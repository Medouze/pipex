/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:57:18 by mlavergn          #+#    #+#             */
/*   Updated: 2024/11/04 22:06:25 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child(char **av, int *p_fd, char **envp)
{
	int		fd;
	char	*path;
	char	**cmd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	if (dup2(fd, 0) == -1)
		exit (1);
	if (dup2(p_fd[1], 1) == -1)
		exit (1);
	close(p_fd[0]);
	cmd = ft_split(av[2], ' ');
	path = check_cmd(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		free_path(cmd);
		free(path);
		exit(1);
	}
}

void	parent(char **av, int *p_fd, char **envp)
{
	int		fd;
	char	*path;
	char	**cmd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(1);
	if (dup2(fd, 1) == -1)
		exit (1);
	if (dup2(p_fd[0], 0) == -1)
		exit (1);
	close(p_fd[1]);
	cmd = ft_split(av[3], ' ');
	path = check_cmd(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		free_path(cmd);
		free(path);
		exit(1);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	id;

	parse_arg(ac);
	if (pipe(fd) == -1)
		exit(1);
	id = fork();
	if (id == -1)
		exit(1);
	if (id == 0)
		child(av, fd, envp);
	else
		parent(av, fd, envp);
	return (0);
}
