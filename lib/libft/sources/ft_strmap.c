/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:19:49 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/26 20:11:00 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*begin;

	if (!f || !s)
		return (0);
	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	begin = str;
	while (*s)
		*str++ = (*f)(*s++);
	*str = 0;
	return (begin);
}
