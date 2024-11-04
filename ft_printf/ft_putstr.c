/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:26:49 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/07 16:58:22 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	size_t	i;

	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = 0;
	while (i < ft_strlen(s))
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
