/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:10:20 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 17:28:44 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualization.h"
#include <mlx.h>
#include <stdio.h>

void	push_ant_in_room(t_link *link, char *buf)
{
	char	**parser;
	t_room	*room;
	t_link	*l;
	int		i;

	parser = ft_strsplit(buf, ' ');
	i = 0;
	l = link;
	while (l)
	{
		l->room->id_ant = 0;
		l = l->next;
	}
	while (parser[i])
	{
		room = find_room(link,
				parser[i] + (ft_strchr(parser[i], '-') - parser[i] + 1));
		room->id_ant = ft_atoi(parser[i] + 1);
		i++;
	}
	ft_strmasfree(&parser);
}

void	print_id_ant(t_global *global, t_link *link)
{
	char	*p;

	mlx_string_put(global->mlx, global->window, (float)
		link->room->pos.x * ROOM_SIZE + ROOM_SIZE /
		2 - 2.5 * PADDING + FIELD_WIDTH / 4, (float)
		link->room->pos.y * ROOM_SIZE + ROOM_SIZE /
		2 - PADDING + FIELD_HEIGHT / 4,
		0x000000, "L");
	mlx_string_put(global->mlx, global->window, (float)
		link->room->pos.x * ROOM_SIZE + ROOM_SIZE /
		2 - PADDING + FIELD_WIDTH / 4, (float)
		link->room->pos.y * ROOM_SIZE + ROOM_SIZE /
		2 - PADDING + FIELD_HEIGHT / 4,
		0x000000, (p = ft_itoa(link->room->id_ant)));
	free(p);
}

void	info(t_global *global)
{
	t_link	*link;

	link = global->rooms;
	while (link)
	{
		mlx_string_put(global->mlx, global->window, (float)
			link->room->pos.x * ROOM_SIZE + PADDING + FIELD_WIDTH / 4, (float)
			link->room->pos.y * ROOM_SIZE + PADDING / 2 + FIELD_HEIGHT / 4,
			0xFFFFFF, link->room->name);
		if (link->room->id_ant)
			print_id_ant(global, link);
		link = link->next;
	}
}

int		deal_key(int key, t_global *global)
{
	if (key == KEY_ESC)
		exit(1);
	else if (key == KEY_SPACE)
		draw(global);
	return (0);
}
