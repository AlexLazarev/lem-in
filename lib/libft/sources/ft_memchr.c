/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:45:59 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/26 18:25:22 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *temp;

	temp = (unsigned char*)s;
	while (n--)
	{
		if (*temp == (unsigned char)c)
			return (temp);
		else
			temp++;
	}
	return (0);
}
