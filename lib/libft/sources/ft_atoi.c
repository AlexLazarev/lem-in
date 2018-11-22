/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:56:27 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/27 15:47:41 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	num;
	int		sign;

	sign = 1;
	num = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		if (num > 2147483647 && sign == 1)
			return (-1);
		else if (num > 2147483648 && sign == -1)
			return (0);
		num *= 10;
		num += *str - 48;
		str++;
	}
	return (sign * num);
}
