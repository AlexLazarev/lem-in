/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:26:03 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/08 19:26:17 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../includes/ft_printf.h"

void		check_octal(char conversion, va_list ap, t_flag *flag)
{
	uintmax_t	number;
	int			size;

	flag->l = conversion == 'O' ? 1 : 0;
	number = get_size_modifier_u(ap, *flag);
	size = 0;
	if ((flag->precision >= 0) || number)
	{
		size = ft_rankunumber_base(number, 8);
		if (flag->sharp && number)
		{
			size += 1;
			precision_width_sign(*flag, size, SIGN_OCTAL);
		}
		else
			precision_width(*flag, size);
		ft_putunbr_base_lower(number, 8);
		if (flag->minus)
			set_width(*flag, size);
	}
	else
		flag->sharp ? precision_width_sign(*flag, ++size, SIGN_OCTAL)
	: set_width(*flag, size);
	flag->size += flag->precision > size ? flag->precision : size;
	flag->size = flag->width > flag->size ? flag->width : flag->size;
}

void		check_udecimal(char conversion, va_list ap, t_flag *flag)
{
	uintmax_t	number;
	int			size;

	if (conversion == 'U')
		flag->l += 1;
	number = get_size_modifier_u(ap, *flag);
	size = 0;
	if ((flag->precision >= 0) || number)
	{
		size = ft_rankunumber_base(number, 10);
		precision_width(*flag, size);
		ft_putunbr_base_lower(number, 10);
		if (flag->minus)
			set_width(*flag, size);
	}
	else
		set_width(*flag, size);
	flag->size += flag->precision > size ? flag->precision : size;
	flag->size = flag->width > flag->size ? flag->width : flag->size;
}

void		check_hex(char format, va_list ap, t_flag *flag)
{
	uintmax_t	number;
	int			size;

	number = get_size_modifier_u(ap, *flag);
	size = 0;
	if ((flag->precision >= 0) || number)
	{
		size = ft_rankunumber_base(number, 16);
		if ((flag->sharp && number))
		{
			flag->precision > 0 ? (flag->size += 2) : (size += 2);
			precision_width_sign(*flag, size, format == 'X' ?
				SIGN_UPPER_HEX : SIGN_LOWER_HEX);
		}
		else
			precision_width(*flag, size);
		format == 'X' ? ft_putunbr_base_upper(number, 16)
		: ft_putunbr_base_lower(number, 16);
		if (flag->minus)
			set_width(*flag, size);
	}
	else
		precision_width(*flag, size);
	flag->size += flag->precision > size ? flag->precision : size;
	flag->size = flag->width > flag->size ? flag->width : flag->size;
}

static void	check_decimal_inner(t_flag *flag, intmax_t number, int size)
{
	if (number < 0)
	{
		flag->plus = 1;
		precision_width_sign(*flag, size, SIGN_MINUS);
		if (number == LONG_MIN)
			ft_putstr("9223372036854775808");
		else
			ft_putunbr(-1 * number);
	}
	else
	{
		precision_width_sign(*flag, size, 0);
		ft_putnbr(number);
	}
	if (flag->minus)
		set_width(*flag, size);
}

void		check_decimal(char conversion, va_list ap, t_flag *flag)
{
	intmax_t	number;
	int			size;

	if (conversion == 'D')
		flag->l += 1;
	number = get_size_modifier(ap, *flag);
	size = 0;
	if ((flag->precision >= 0) || number)
	{
		size = ft_ranknumber_base(number, 10);
		check_decimal_inner(flag, number, size);
	}
	else
		set_width(*flag, size);
	flag->size += flag->precision > size ? flag->precision : size;
	flag->size += (flag->plus ? flag->plus : flag->space);
	flag->size = flag->width > flag->size ? flag->width : flag->size;
}
