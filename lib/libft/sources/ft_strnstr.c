/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:42:54 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/27 18:42:39 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *base, const char *find, size_t len)
{
	const char	*b_temp;
	const char	*f_temp;
	size_t		l_temp;

	if (!*find)
		return (char*)base;
	if (!ft_strcmp(base, find))
		return ((char*)base);
	while (*base && len--)
	{
		if (*base == *find)
		{
			b_temp = base;
			f_temp = find;
			l_temp = len + 1;
			while (*b_temp++ == *f_temp++ && l_temp--)
				if (*f_temp == '\0')
					return ((char*)base);
		}
		base++;
	}
	return (0);
}
