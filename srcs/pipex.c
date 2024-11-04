/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:57:18 by mlavergn          #+#    #+#             */
/*   Updated: 2024/11/04 22:54:47 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child(char **av, int *p_fd, char **envp)
{
	int		fd;
	char	*path;
	char	**cmd;

	ft_error(fd = open(av[1], O_RDONLY));
	ft_error(dup2(fd, STDIN_FILENO) == -1);
	ft_error(dup2(p_fd[1], STDOUT_FILENO) == -1);
	ft_error(close(p_fd[0]));
	cmd = ft_split(av[2], ' ');
	path = check_cmd(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		free_path(cmd);
		free(path);
		exit(EXIT_FAILURE);
	}
}

void	parent(char **av, int *p_fd, char **envp)
{
	int		fd;
	char	*path;
	char	**cmd;

	ft_error(fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777));
	ft_error(dup2(fd, STDOUT_FILENO) == -1);
	ft_error(dup2(p_fd[0], STDIN_FILENO) == -1);
	ft_error(close(p_fd[1]));
	cmd = ft_split(av[3], ' ');
	path = check_cmd(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		free_path(cmd);
		free(path);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	id;

	parse_arg(ac);
	ft_error(pipe(fd) == -1);
	id = fork();
	ft_error(id);
	if (id == 0)
		child(av, fd, envp);
	else
		parent(av, fd, envp);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
