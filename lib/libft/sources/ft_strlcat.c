/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:09:15 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/26 16:15:50 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 >= n)
		return (n + len2);
	while (*s1 && n--)
		s1++;
	while (*s2 && --n)
		*s1++ = *s2++;
	*s1 = 0;
	return (len1 + len2);
}
