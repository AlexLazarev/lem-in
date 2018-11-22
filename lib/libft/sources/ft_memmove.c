/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:04:52 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/23 21:35:38 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*begin;

	begin = dst;
	if (dst < src)
		while (len--)
			*((unsigned char*)dst++) = *((unsigned char*)src++);
	else
		while (len--)
			*((unsigned char*)(dst + len)) = *((unsigned char*)(src + len));
	return (begin);
}
