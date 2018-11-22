/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_unicode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 20:02:26 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/08 20:02:37 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../includes/ft_printf.h"

static void	manipulation_string(t_flag *flag, char *str)
{
	int n;
	int len;

	n = 0;
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		n = 1;
	}
	len = ft_strlen(str);
	if (!flag->minus)
		set_width_unicode(*flag, len, IS_STRING);
	if (flag->precision && flag->precision < len)
		write(1, str, flag->precision);
	else
		ft_putstr(str);
	if (flag->minus)
		set_width_unicode(*flag, len, IS_STRING);
	if (flag->precision < len && flag->precision != 0)
		flag->size = (flag->width > flag->precision ?
			flag->width : flag->precision);
	else
		flag->size = (flag->width > len ? flag->width : len);
	if (n)
		free(str);
}

void		check_string(va_list ap, t_flag *flag)
{
	char *str;

	if (flag->l)
		check_unicode_str(ap, flag);
	else
	{
		str = va_arg(ap, char *);
		manipulation_string(flag, str);
	}
}

void		check_unicode(char conversion, t_flag *flag, unsigned int c)
{
	int byte;

	if (conversion == 'c' && !flag->l)
		byte = 1;
	else
		byte = byte_unicode(ft_ranknumber_base(c, 2));
	if (!flag->minus)
		set_width_unicode(*flag, byte, IS_CHAR);
	print_unicode(c, byte);
	if (flag->minus)
		set_width_unicode(*flag, byte, IS_CHAR);
	flag->size = (flag->width > byte ? flag->width : byte);
}

static void	check_unicode_str_inner(t_flag *flag, wchar_t *str, int byte)
{
	int i;
	int temp;
	int curr_byte;

	if (!flag->minus)
		set_width_unicode(*flag, byte, IS_STRING);
	i = -1;
	temp = byte;
	while (str[++i])
	{
		curr_byte = byte_unicode(ft_ranknumber_base(str[i], 2));
		if (temp - curr_byte < 0)
			break ;
		temp -= curr_byte;
		print_unicode(str[i], curr_byte);
		flag->size += curr_byte;
	}
	if (flag->minus)
		set_width_unicode(*flag, byte, IS_STRING);
}

void		check_unicode_str(va_list ap, t_flag *flag)
{
	int				byte;
	wchar_t			*str;
	int				i;
	int				temp;

	str = va_arg(ap, wchar_t*);
	byte = 0;
	i = -1;
	if (str)
	{
		while (str[++i])
		{
			temp = byte_unicode(ft_ranknumber_base(str[i], 2));
			if (flag->precision >= byte + temp || flag->precision == 0)
				byte += temp;
		}
		check_unicode_str_inner(flag, str, byte);
		flag->size = (flag->width > flag->size ? flag->width : flag->size);
	}
	else
		manipulation_string(flag, NULL);
}
