/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 18:28:11 by alazarev          #+#    #+#             */
/*   Updated: 2018/04/08 19:37:40 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char **s, size_t len)
{
	char	*str;

	if (!*s)
	{
		str = ft_strnew(len);
		return (str);
	}
	str = ft_strnew(ft_strlen(*s) + len);
	ft_strcpy(str, *s);
	ft_strdel(&(*s));
	return (str);
}
