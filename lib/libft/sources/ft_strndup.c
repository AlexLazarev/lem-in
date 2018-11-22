/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:33:39 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 17:33:51 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (0);
	str[n] = '\0';
	while (i < n)
	{
		str[i] = (char)s1[i];
		i++;
	}
	return (str);
}
