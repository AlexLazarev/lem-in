/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmasnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:07:50 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/15 17:09:09 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strmasnew(int x, int y)
{
	int		i;
	char	**mas;

	mas = (char**)malloc(sizeof(char*) * (y + 1));
	i = 0;
	while (i < y)
	{
		mas[i] = (char*)malloc(sizeof(char) * (x + 1));
		i++;
	}
	return (mas);
}
