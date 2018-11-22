/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrvrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:28:08 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/26 20:08:22 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrvrs(char const *s)
{
	int		len;
	int		i;
	char	*str;

	len = ft_strlen(s);
	if (!(str = ft_strnew(len)))
		return (0);
	i = 0;
	while (len--)
		str[i++] = s[len];
	return (str);
}
