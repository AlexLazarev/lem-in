/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:17:25 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 14:20:03 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include "../includes/error.h"

char	**valid_room(t_lemin *lemin, char *buf)
{
	char	**parse;
	t_point p;
	t_point	len;

	if (ft_charcount(buf, ' ') != 2)
		error(ERROR_ROOM);
	parse = ft_strsplit(buf, ' ');
	if (ft_strmaslen(parse) != 3)
		error(ERROR_ROOM);
	if (*(parse[0]) == 'L' || ft_strchr(parse[0], '-')
			|| find_room(lemin->rooms, parse[0]))
		error(ERROR_ROOM_NAME);
	len.x = ft_strlen(parse[1]);
	p.x = ft_atoi(parse[1]);
	len.y = ft_strlen(parse[2]);
	p.y = ft_atoi(parse[2]);
	if (len.x != ft_rank(p.x) ||
			len.y != ft_rank(p.y) ||
			(!ft_isdigit(*parse[1]) && ft_strlen(parse[1]) == 1) ||
			(!ft_isdigit(*parse[2]) && ft_strlen(parse[2]) == 1) ||
			find_room_by_pos(lemin->rooms, p))
		error(ERROR_ROOM_POS);
	return (parse);
}

char	**valid_link(t_lemin *lemin, char *buf)
{
	char **parse;

	parse = NULL;
	if (ft_charcount(buf, '-') == 1)
	{
		parse = ft_strsplit(buf, '-');
		if (ft_strmaslen(parse) == 2)
		{
			if (!find_room(lemin->rooms, parse[0])
					|| !find_room(lemin->rooms, parse[1]))
				error(ERROR_LINK_NAME);
		}
		else
			error(ERROR_LINK);
	}
	else
		error(ERROR_LINK);
	return (parse);
}

int		valid_ant(char *buf)
{
	int len;
	int ant;

	len = ft_strlen(buf);
	ant = ft_atoi(buf);
	if (len != ft_ranknumber_base(ant, 10) || ant <= 0)
		error(ERROR_ANT_SIZE);
	return (ant);
}
