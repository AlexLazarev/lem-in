/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:27:10 by alazarev          #+#    #+#             */
/*   Updated: 2018/04/25 16:27:11 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../includes/ft_printf.h"

static void	init(const char **format, t_flag *flag)
{
	init_flags(flag, format);
	if (!(flag->l = check_size_modifier(format, 'l')))
		if (!(flag->h = check_size_modifier(format, 'h')))
			if (!(flag->j = check_size_modifier(format, 'j')))
				flag->z = check_size_modifier(format, 'z');
}

static int	find_conversation(const char **format, va_list ap, t_flag *flag)
{
	if (**format == 'o' || **format == 'O')
		check_octal(**format, ap, flag);
	else if (**format == 'u' || **format == 'U')
		check_udecimal(**format, ap, flag);
	else if (**format == 'x' || **format == 'X')
		check_hex(**format, ap, flag);
	else if (**format == 'p')
		check_pointer(ap, flag);
	else if (**format == 'd' || **format == 'i' || **format == 'D')
		check_decimal(**format, ap, flag);
	else if (**format == 's')
		check_string(ap, flag);
	else if (**format == '%')
		check_percent(flag);
	else if (**format == 'c' || **format == 'C')
		check_unicode(**format, flag, va_arg(ap, unsigned int));
	else if (**format == 'S')
		check_unicode_str(ap, flag);
	else if (**format)
		check_unicode(**format, flag, **format);
	else
		return (0);
	return (1);
}

static int	check_flags(const char **format, va_list ap)
{
	t_flag	flag;

	init(format, &flag);
	if (find_conversation(format, ap, &flag))
	{
		(*format)++;
		return (flag.size);
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	char			*index;
	int				step;
	unsigned int	size;

	va_start(ap, format);
	size = 0;
	while (*format)
	{
		index = ft_strchr(format, '%');
		if (index)
		{
			write(1, format, (step = index - format));
			format += step + 1;
			size += check_flags(&format, ap) + step;
		}
		else
		{
			write(1, format, (step = ft_strlen(format)));
			size += step;
			break ;
		}
	}
	va_end(ap);
	return (size);
}
