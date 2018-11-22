/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:28:59 by alazarev          #+#    #+#             */
/*   Updated: 2018/04/25 16:29:35 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "../sources/libft.h"

# define LONG_MIN -9223372036854775807 - 1
# define SIGN_MINUS 1
# define SIGN_OCTAL 2
# define SIGN_LOWER_HEX 3
# define SIGN_UPPER_HEX 4
# define ERROR_ZERO_PRECISION -2
# define ERROR_DOT_PRECISION -1
# define IS_CHAR 1
# define IS_STRING 0

typedef struct	s_flag
{
	short	l;
	short	h;
	short	j;
	short	z;
	short	minus;
	short	plus;
	short	zero;
	short	sharp;
	short	space;
	int		precision;
	int		width;
	int		size;
}				t_flag;

int				ft_printf(const char *restrict format, ...);
void			check_flag_num(const char **format, int *flag);
void			check_flag(const char **format, short *flag, char sign);
int				check_size_modifier(const char **format, char flag);
intmax_t		get_size_modifier(va_list ap, t_flag flag);
uintmax_t		get_size_modifier_u(va_list ap, t_flag flag);
void			precision_width(t_flag flag, int size);
void			precision_width_sign(t_flag flag, int size, int sign);
void			set_width(t_flag flag, int size);
void			set_width_unicode(t_flag flag, int byte, int is_char);
void			set_sign(t_flag flag, int sign);
void			init_flags(t_flag *flag, const char **format);
void			print_unicode(unsigned int value, int byte);
int				byte_unicode(int bits);
void			check_unicode_str(va_list ap, t_flag *flag);
void			check_unicode(char conversion, t_flag *flag, unsigned int c);
void			check_string(va_list ap, t_flag *flag);
void			check_percent(t_flag *flag);
void			check_decimal(char conversion, va_list ap, t_flag *flag);
void			check_hex(char format, va_list ap, t_flag *flag);
void			check_octal(char conversion, va_list ap, t_flag *flag);
void			check_udecimal(char conversion, va_list ap, t_flag *flag);
void			check_pointer(va_list ap, t_flag *flag);

#endif
