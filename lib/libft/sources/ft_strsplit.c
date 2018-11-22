/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:05:52 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/26 19:19:31 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_crtword(char const *s, int len)
{
	char	*mas;

	if (!(mas = ft_strnew(len)))
		return (0);
	return (ft_strncpy(mas, (s - len), len));
}

char			**ft_strsplit(char const *s, char c)
{
	char	**mas;
	char	**begin;
	int		len;

	if (!s)
		return (0);
	len = 0;
	if (!(mas = (char**)malloc(sizeof(char*) * (ft_strnsplit(s, c) + 1))))
		return (0);
	begin = mas;
	while (*s)
	{
		if (*s == c && len)
			*mas++ = ft_crtword(s, len);
		len++;
		if (*s == c)
			len = 0;
		s++;
	}
	if (len)
		*mas++ = ft_crtword(s, len);
	*mas = 0;
	return (begin);
}
