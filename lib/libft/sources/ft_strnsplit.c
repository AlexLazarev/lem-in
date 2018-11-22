/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:22:26 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/24 16:02:54 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnsplit(char const *s, char c)
{
	size_t	count;
	int		flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (flag)
				count++;
			flag = 0;
		}
		else
			flag = 1;
		s++;
	}
	if (flag)
		return (count + 1);
	return (count);
}
