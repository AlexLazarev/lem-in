/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:46:38 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/26 18:25:07 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		if (*((unsigned char*)src) == (unsigned char)c)
		{
			*((unsigned char*)dst++) = (unsigned char)c;
			return ((unsigned char*)dst);
		}
		*((unsigned char*)dst++) = *((unsigned char*)src++);
	}
	return (NULL);
}
