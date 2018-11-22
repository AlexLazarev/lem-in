/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 10:29:55 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/27 17:06:53 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			ft_putnbr(147483648);
		}
		else
			ft_putnbr(-n);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_putunbr(uintmax_t n)
{
	if (n <= 9)
		ft_putchar(n + 48);
	else
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
}

void	ft_putunbr_base_upper(unsigned long long n, int base)
{
	if (n < (unsigned long long)base)
		ft_putchar(n + (n > 9 ? 'A' - 10 : '0'));
	else
	{
		ft_putunbr_base_upper(n / base, base);
		ft_putunbr_base_upper(n % base, base);
	}
}

void	ft_putunbr_base_lower(unsigned long long n, int base)
{
	if (n < (unsigned long long)base)
		ft_putchar(n + (n > 9 ? 'a' - 10 : '0'));
	else
	{
		ft_putunbr_base_lower(n / base, base);
		ft_putunbr_base_lower(n % base, base);
	}
}
