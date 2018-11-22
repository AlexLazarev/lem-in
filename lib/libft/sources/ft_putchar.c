/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 10:27:26 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/25 10:28:16 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnchar(char c, int n)
{
	char *str;

	if (n > 0)
	{
		str = ft_strnew(n);
		ft_memset(str, c, n);
		write(1, str, n);
		free(str);
	}
}
