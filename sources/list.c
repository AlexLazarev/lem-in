/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:35:28 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 16:38:18 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include "../includes/error.h"

t_room	*find_room_by_pos(t_link *link, t_point pos)
{
	while (link)
	{
		if (link->room->pos.x == pos.x
				&& link->room->pos.y == pos.y)
			return (link->room);
		link = link->next;
	}
	return (NULL);
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
	t_link	*cur;

	cur = *begin;
	if (*begin != NULL)
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
	else
		*begin = new;
}

size_t	get_link_len(t_link *link)
{
	size_t len;

	len = 0;
	while (link)
	{
		len++;
		link = link->next;
	}
	return (len);
}
