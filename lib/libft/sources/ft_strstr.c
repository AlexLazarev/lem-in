/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:30:30 by alazarev          #+#    #+#             */
/*   Updated: 2018/03/22 16:27:11 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_strstr(const char *base, const char *find)
{
	const char	*b_temp;
	const char	*f_temp;

	if (*find == '\0')
		return (char*)base;
	while (*base)
	{
		if (*base == *find)
		{
			b_temp = base;
			f_temp = find;
			while (*b_temp++ == *f_temp++)
				if (*f_temp == '\0')
					return ((char*)base);
		}
		base++;
	}
	return (0);
}
