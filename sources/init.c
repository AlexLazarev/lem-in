/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:38:32 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 16:42:43 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include "../includes/error.h"

static void	norm(t_lemin *lemin, char *buf)
{
	lemin->start = create_room(lemin, buf);
	link_push(&lemin->rooms, create_link(lemin->start));
}

void		init_sf(t_lemin *lemin, char *str)
{
	char *buf;

	while (get_next_line(0, &buf) > 0)
	{
		init_info(lemin, buf);
		if (!is_comment(buf))
		{
			if (!ft_strcmp(str, START))
			{
				if (lemin->start)
					error(ERROR_ONLY_ONE_START);
				norm(lemin, buf);
			}
			else if (!ft_strcmp(str, FINISH))
			{
				if (lemin->finish)
					error(ERROR_ONLY_ONE_FINISH);
				lemin->finish = create_room(lemin, buf);
				link_push(&lemin->rooms, create_link(lemin->finish));
			}
			free(buf);
			break ;
		}
		free(buf);
	}
}

int			init_rooms(t_lemin *lemin, char *buf)
{
	if (ft_strchr(buf, '-') && !ft_strchr(buf, ' '))
	{
		if (!lemin->start)
			error(ERROR_ROOM_START);
		if (!lemin->finish)
			error(ERROR_ROOM_FINISH);
		return (ROOM_COMPLETE);
	}
	else if (!ft_strcmp(buf, START) || !ft_strcmp(buf, FINISH))
		init_sf(lemin, buf);
	else
		link_push(&lemin->rooms, create_link(create_room(lemin, buf)));
	return (ROOM_IN_PROCESS);
}

void		init_links(t_lemin *lemin, char *buf)
{
	t_room	*room;
	t_room	*neighbor;
	char	**parse;

	parse = valid_link(lemin, buf);
	room = find_room(lemin->rooms, parse[0]);
	neighbor = find_room(lemin->rooms, parse[1]);
	link_push(&room->link, create_link(neighbor));
	link_push(&neighbor->link, create_link(room));
	ft_strmasfree(&parse);
}

int			init_ants(t_lemin *lemin, char *buf)
{
	lemin->ant = valid_ant(buf);
	return (ANT_COMPLETE);
}
