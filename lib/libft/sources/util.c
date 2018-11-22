/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:48:14 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/09 15:48:56 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

void		check_flag_precision(const char **format, t_flag *flag)
{
	if (**format == '.')
	{
		(*format)++;
		if (ft_isdigit(**format))
		{
			check_flag_num(format, &flag->precision);
			if (flag->precision == 0)
				flag->precision = ERROR_ZERO_PRECISION;
		}
		else
			flag->precision = ERROR_DOT_PRECISION;
	}
	else
		flag->precision = 0;
}

void		init_flags(t_flag *flag, const char **format)
{
	flag->minus = 0;
	flag->plus = 0;
	flag->zero = 0;
	flag->sharp = 0;
	flag->space = 0;
	flag->size = 0;
	while (is_flag(**format))
	{
		check_flag(format, &flag->minus, '-');
		check_flag(format, &flag->plus, '+');
		check_flag(format, &flag->zero, '0');
		check_flag(format, &flag->sharp, '#');
		check_flag(format, &flag->space, ' ');
	}
	check_flag_num(format, &flag->width);
	check_flag_precision(format, flag);
	if (flag->minus || flag->precision > 0)
		flag->zero = 0;
	if (flag->plus)
		flag->space = 0;
}
