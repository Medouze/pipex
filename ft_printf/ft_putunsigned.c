/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:57:13 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/07 16:58:10 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	long	nbr;
	int		count;

	nbr = n;
	count = 0;
	if (nbr <= 9)
	{
		nbr = nbr + '0';
		count += ft_putchar(nbr);
	}
	else
	{
		count += ft_putunsigned(nbr / 10);
		count += ft_putunsigned(nbr % 10);
	}
	return (count);
}
