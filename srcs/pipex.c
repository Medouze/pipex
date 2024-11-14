/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:57:18 by mlavergn          #+#    #+#             */
/*   Updated: 2024/11/14 15:56:15 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child(char **av, int *p_fd, char **envp)
{
	int		fd;

	ft_error(fd = open(av[1], O_RDONLY));
	ft_error(dup2(fd, STDIN_FILENO) == -1);
	ft_error(dup2(p_fd[1], STDOUT_FILENO) == -1);
	ft_error(close(p_fd[0]));
	exec_cmd(av[2], envp);
}

void	parent(char **av, int *p_fd, char **envp)
{
	int		fd;

	ft_error(fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777));
	ft_error(dup2(fd, STDOUT_FILENO) == -1);
	ft_error(dup2(p_fd[0], STDIN_FILENO) == -1);
	ft_error(close(p_fd[1]));
	exec_cmd(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	id;

	if (ac == 5)
	{
		ft_error(pipe(fd) == -1);
		id = fork();
		ft_error(id);
		if (id == 0)
			child(av, fd, envp);
		else
			parent(av, fd, envp);
		close(fd[0]);
		close(fd[1]);
	}
	return (0);
}
