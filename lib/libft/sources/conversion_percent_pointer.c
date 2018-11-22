/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 20:04:03 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/09 15:44:46 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_percent(t_flag *flag)
{
	if (!flag->minus)
		set_width(*flag, IS_CHAR);
	ft_putchar('%');
	if (flag->minus)
		set_width(*flag, IS_CHAR);
	flag->size = (flag->width > 0 ? flag->width : 1);
}

void	check_pointer(va_list ap, t_flag *flag)
{
	uintmax_t	number;
	int			size;

	flag->l = 1;
	number = get_size_modifier_u(ap, *flag);
	size = 2;
	if ((flag->precision >= 0) || number)
	{
		size += ft_rankunumber_base(number, 16);
		precision_width_sign(*flag, flag->precision > flag->width ?
			size - 2 : size, SIGN_LOWER_HEX);
		ft_putunbr_base_lower(number, 16);
		if (flag->minus)
			set_width(*flag, size);
	}
	else
		precision_width_sign(*flag, size, SIGN_LOWER_HEX);
	flag->size += flag->precision > size ?
	flag->precision + 2 : size;
	if (flag->precision && !number)
		flag->size += 0;
	else
		flag->size = flag->width > flag->size ? flag->width : flag->size;
}
