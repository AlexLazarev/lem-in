/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:44:48 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 17:30:48 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualization.h"

t_link	*create_link(t_room *room)
{
	t_link	*link;

	link = (t_link*)malloc(sizeof(t_link));
	link->room = room;
	link->next = NULL;
	return (link);
}

void	link_push(t_link **begin, t_link *new)
{
	new->next = *begin;
	*begin = new;
}

t_room	*create_room(char *buf)
{
	t_room	*room;
	char	**parse;

	parse = ft_strsplit(buf, ' ');
	room = (t_room*)malloc(sizeof(t_room));
	room->name = ft_strdup(parse[0]);
	room->pos.x = ft_atoi(parse[1]);
	room->pos.y = ft_atoi(parse[2]);
	room->link = NULL;
	room->id_ant = 0;
	ft_strmasfree(&parse);
	return (room);
}

t_room	*find_room(t_link *link, char *name)
{
	while (link)
	{
		if (!ft_strcmp(link->room->name, name))
			return (link->room);
		link = link->next;
	}
	return (NULL);
}

void	init_links(t_global *global, char *buf)
{
	t_room	*room;
	t_room	*neighbor;
	char	**parse;

	parse = ft_strsplit(buf, '-');
	room = find_room(global->rooms, parse[0]);
	neighbor = find_room(global->rooms, parse[1]);
	link_push(&room->link, create_link(neighbor));
	link_push(&neighbor->link, create_link(room));
	ft_strmasfree(&parse);
}
