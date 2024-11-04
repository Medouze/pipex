/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:57:49 by mlavergn          #+#    #+#             */
/*   Updated: 2024/11/04 22:30:52 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

void	parse_arg(int ac);
char	*check_cmd(char *cmd, char **envp);
char	*get_env(char *name, char **envp);
void	free_path(char **path);
void	ft_error(int retur);
