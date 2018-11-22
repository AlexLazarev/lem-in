/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_getter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:55:35 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/09 15:55:36 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		check_flag(const char **format, short *flag, char sign)
{
	if (**format == sign)
	{
		*flag = 1;
		(*format)++;
	}
}

void		check_flag_num(const char **format, int *flag)
{
	*flag = 0;
	while (ft_isdigit(**format))
	{
		*flag *= 10;
		*flag += **format - 48;
		(*format)++;
	}
}

int			check_size_modifier(const char **format, char flag)
{
	if (**format == flag)
	{
		(*format)++;
		if (**format == flag)
		{
			(*format)++;
			return (2);
		}
		return (1);
	}
	return (0);
}

intmax_t	get_size_modifier(va_list ap, t_flag flag)
{
	if (flag.l == 1)
		return (va_arg(ap, long));
	else if (flag.l == 2)
		return (va_arg(ap, long long));
	else if (flag.h == 1)
		return (short)(va_arg(ap, int));
	else if (flag.h == 2)
		return (char)(va_arg(ap, int));
	else if (flag.j)
		return (va_arg(ap, uintmax_t));
	else if (flag.z)
		return (va_arg(ap, size_t));
	return (va_arg(ap, int));
}

uintmax_t	get_size_modifier_u(va_list ap, t_flag flag)
{
	if (flag.l == 1)
		return (va_arg(ap, unsigned long));
	else if (flag.l == 2)
		return (va_arg(ap, unsigned long long));
	else if (flag.h == 1)
		return (unsigned short)(va_arg(ap, int));
	else if (flag.h == 2)
		return (unsigned char)(va_arg(ap, int));
	else if (flag.j)
		return (va_arg(ap, uintmax_t));
	else if (flag.z)
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned));
}
