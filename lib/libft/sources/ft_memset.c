/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:31:01 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/23 13:33:26 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *mem, int sign, size_t len)
{
	void	*begin;

	begin = mem;
	while (len--)
		*((unsigned char*)mem++) = (unsigned char)sign;
	return (begin);
}
