/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 20:17:59 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/08 20:18:00 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	mask1(unsigned int value)
{
	unsigned int	mask;
	unsigned char	b1;
	unsigned char	b2;
	unsigned char	b;

	mask = 49280;
	b1 = (value << 26) >> 26;
	b2 = value >> 6;
	b = (mask >> 8) | b2;
	write(1, &b, 1);
	b = (mask << 8) >> 8 | b1;
	write(1, &b, 1);
}

void	mask2(unsigned int value)
{
	unsigned int	mask;
	unsigned char	b1;
	unsigned char	b2;
	unsigned char	b3;
	unsigned char	b;

	mask = 14712960;
	b1 = (value << 26) >> 26;
	b2 = (value << 20) >> 26;
	b3 = value >> 12;
	b = (mask >> 16) | b3;
	write(1, &b, 1);
	b = (mask << 8) >> 16 | b2;
	write(1, &b, 1);
	b = (mask << 16) >> 16 | b1;
	write(1, &b, 1);
}

void	mask3(unsigned int value)
{
	unsigned int	mask;
	unsigned char	bn[4];
	unsigned char	b;

	mask = 4034953344;
	bn[0] = (value << 26) >> 26;
	bn[1] = (value << 20) >> 26;
	bn[2] = (value << 14) >> 26;
	bn[3] = value >> 18;
	b = (mask >> 24) | bn[3];
	write(1, &b, 1);
	b = (mask << 8) >> 24 | bn[2];
	write(1, &b, 1);
	b = (mask << 16) >> 24 | bn[1];
	write(1, &b, 1);
	b = (mask << 24) >> 24 | bn[0];
	write(1, &b, 1);
}

void	print_unicode(unsigned int value, int byte)
{
	if (byte == 1)
		ft_putchar(value);
	else if (byte == 2)
		mask1(value);
	else if (byte == 3)
		mask2(value);
	else
		mask3(value);
}

int		byte_unicode(int bits)
{
	if (bits < 8)
		return (1);
	if (bits < 12)
		return (2);
	if (bits < 17)
		return (3);
	return (4);
}
