/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 01:52:47 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/07 16:54:04 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(char c, unsigned int n)
{
	char	hex[17];
	long	nbr;
	int		count;

	count = 0;
	nbr = n;
	if (c == 'x')
		ft_strlcpy(hex, "0123456789abcdef", 17);
	if (c == 'X')
		ft_strlcpy(hex, "0123456789ABCDEF", 17);
	if (nbr <= 15)
		count += ft_putchar(hex[nbr]);
	else
	{
		count += ft_putnbr_hex(c, nbr / 16);
		count += ft_putnbr_hex(c, nbr % 16);
	}
	return (count);
}
