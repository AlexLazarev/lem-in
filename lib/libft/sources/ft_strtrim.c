/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 20:12:55 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/26 19:02:13 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		len;
	char	*str;

	if (!s)
		return (0);
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	len = (ft_strlen(s));
	while (len-- && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		;
	str = ft_strnew(len + 1);
	if (!str)
		return (0);
	ft_strncpy(str, s, len + 1);
	return (str);
}
