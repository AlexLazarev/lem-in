/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:53:31 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/26 19:19:05 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*begin;

	if (!(str = ft_strnew(len)) || !s)
		return (0);
	begin = str;
	while (s[start] && len--)
		*str++ = s[start++];
	*str = 0;
	return (begin);
}
