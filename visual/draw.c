/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:50:41 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 17:43:06 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualization.h"
#include <mlx.h>
#include <stdlib.h>

static int	get_color(t_global *global, t_room *room)
{
	t_rgb color;

	if (room == global->start)
		color.rgba = 0x66B32C;
	else if (room == global->finish)
		color.rgba = 0xAE0E29;
	else if (room->id_ant == 0)
		color.rgba = 0x7AC3F3;
	else
		color.rgba = 0x1D6DAB;
	return (color.rgba);
}

static void	draw_connection(t_global *global, t_room *room)
{
	t_link	*link;
	int		p1[2];
	int		p2[2];
	int		p[2];

	p[X] = PADDING + (room->pos.x * ROOM_SIZE) + FIELD_WIDTH / 4;
	p[Y] = PADDING + (room->pos.y * ROOM_SIZE) + FIELD_HEIGHT / 4;
	link = room->link;
	while (link)
	{
		p1[X] = p[X];
		p1[Y] = p[Y];
		p2[X] = PADDING + (link->room->pos.x * ROOM_SIZE) + FIELD_WIDTH / 4;
		p2[Y] = PADDING + (link->room->pos.y * ROOM_SIZE) + FIELD_HEIGHT / 4;
		if (link->room->id_ant > 0)
			draw_line(global, p1, p2, 0xFDDCB7);
		else
			draw_line(global, p1, p2, 0xFF7700);
		link = link->next;
	}
}

static void	draw_rectangle(t_global *global, int color, int i, int j)
{
	int w;
	int h;

	h = -1;
	while (++h < ROOM_SIZE - PADDING)
	{
		w = -1;
		while (++w < ROOM_SIZE - PADDING)
		{
			fill_image(global->image,
				w + PADDING + (j * ROOM_SIZE) + FIELD_WIDTH / 4,
				h + PADDING + (i * ROOM_SIZE) + FIELD_HEIGHT / 4,
				color);
		}
	}
}

static void	draw_item(t_global *global)
{
	t_link	*link;

	link = global->rooms;
	while (link)
	{
		draw_connection(global, link->room);
		link = link->next;
	}
	link = global->rooms;
	while (link)
	{
		draw_rectangle(global, get_color(global, link->room),
			link->room->pos.y, link->room->pos.x);
		link = link->next;
	}
}

int			draw(t_global *global)
{
	char	*buf;

	if (get_next_line(0, &buf) > 0 && *buf == 'L' && ft_isdigit(*(buf + 1)))
	{
		push_ant_in_room(global->rooms, buf);
		draw_item(global);
		mlx_clear_window(global->mlx, global->window);
		mlx_put_image_to_window(global->mlx, global->window,
				global->image->img, 0, 0);
		info(global);
		free(buf);
	}
	return (0);
}
