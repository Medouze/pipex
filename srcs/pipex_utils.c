/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:05:21 by mlavergn          #+#    #+#             */
/*   Updated: 2024/11/04 22:31:40 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(int retur)
{
	if (retur == -1)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		exit(1);
	}
}

void	parse_arg(int ac)
{
	if (ac != 5)
	{
		ft_printf("Format argument should be <file cmd cmd file>\n");
		exit(1);
	}
}

void	free_path(char **path)
{
	int	i;

	i = 0;
	if (path == NULL)
		return ;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

char	*get_env(char *name, char **envp)
{
	int	i;
	int	name_len;

	i = 0;
	name_len = ft_strlen(name);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, name_len) == 0
			&& envp[i][name_len] == '=')
			return (envp[i] + name_len + 1);
		i++;
	}
	return (NULL);
}

char	*check_cmd(char *cmd, char **envp)
{
	char	**all_paths;
	int		i;
	char	*full_path;
	char	*exec_path;

	all_paths = ft_split(get_env("PATH", envp), ':');
	if (!all_paths)
		return (0);
	i = 0;
	while (all_paths[i])
	{
		full_path = ft_strjoin(all_paths[i], "/");
		exec_path = ft_strjoin(full_path, cmd);
		free(full_path);
		if (!access(exec_path, F_OK | X_OK))
		{
			free_path(all_paths);
			return (exec_path);
		}
		free(exec_path);
		i++;
	}
	free_path(all_paths);
	return (NULL);
}
