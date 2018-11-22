/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_setter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:51:15 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/09 15:52:06 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	precision_width(t_flag flag, int size)
{
	if (!flag.minus)
		set_width(flag, size);
	ft_putnchar('0', flag.precision - size);
}

void	precision_width_sign(t_flag flag, int size, int sign)
{
	if (flag.zero)
		set_sign(flag, sign);
	if (!flag.minus)
		set_width(flag, size);
	if (!flag.zero)
		set_sign(flag, sign);
	ft_putnchar('0', flag.precision - size);
}

void	set_width(t_flag flag, int size)
{
	int len;

	len = (flag.precision - size) > 0 ?
	flag.width - flag.precision - flag.plus - flag.space :
	flag.width - size - flag.plus - flag.space;
	if (flag.zero)
		ft_putnchar('0', len);
	else
		ft_putnchar(' ', len);
}

void	set_width_unicode(t_flag flag, int size, int is_char)
{
	int len;

	len = is_char;
	if (flag.precision > 0)
		len = flag.precision > size ? size : flag.precision;
	else if (flag.precision >= 0)
		len = size;
	if (flag.zero)
		ft_putnchar('0', flag.width - len);
	else
		ft_putnchar(' ', flag.width - len);
}

void	set_sign(t_flag flag, int sign)
{
	if (sign == SIGN_MINUS)
		ft_putchar('-');
	else if (sign == SIGN_OCTAL)
		ft_putchar('0');
	else if (sign == SIGN_LOWER_HEX)
		write(1, "0x", 2);
	else if (sign == SIGN_UPPER_HEX)
		write(1, "0X", 2);
	else if (flag.plus)
		ft_putchar('+');
	else if (flag.space)
		ft_putchar(' ');
}
