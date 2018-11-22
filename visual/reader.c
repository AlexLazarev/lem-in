/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:49:36 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 17:29:03 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualization.h"

void	init_sf(t_global *global, char *str)
{
	char *buf;

	while (get_next_line(0, &buf) > 0)
	{
		if (*buf == '#')
		{
			free(buf);
			continue;
		}
		if (!ft_strcmp(str, START))
		{
			global->start = create_room(buf);
			link_push(&global->rooms, create_link(global->start));
		}
		else
		{
			global->finish = create_room(buf);
			link_push(&global->rooms, create_link(global->finish));
		}
		free(buf);
		break ;
	}
}

void	init_rooms(t_global *global)
{
	char *buf;

	get_next_line(0, &buf);
	global->rooms = NULL;
	if (buf)
	{
		if (*buf == ' ')
			ft_error("Some trouble with input!");
		while (*buf != '\0')
		{
			if (*buf != '#' && ft_charcount(buf, ' ') == 2)
				link_push(&global->rooms, create_link(create_room(buf)));
			else if (!ft_strcmp(buf, START) || !ft_strcmp(buf, FINISH))
				init_sf(global, buf);
			else if (*buf != '#' && ft_strchr(buf, '-') && !ft_strchr(buf, ' '))
				init_links(global, buf);
			free(buf);
			get_next_line(0, &buf);
		}
		free(buf);
	}
}
