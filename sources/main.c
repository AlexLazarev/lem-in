/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:03:41 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 17:03:05 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_room		*create_room(t_lemin *lemin, char *buf)
{
	t_room	*room;
	char	**parse;

	parse = valid_room(lemin, buf);
	room = (t_room*)malloc(sizeof(t_room));
	room->name = ft_strdup(parse[0]);
	room->pos.x = ft_atoi(parse[1]);
	room->pos.y = ft_atoi(parse[2]);
	room->step = MAX_VALUE;
	room->is_available = TRUE;
	room->link = NULL;
	ft_strmasfree(&parse);
	return (room);
}

static void	fill(t_room *start)
{
	t_link *curr;
	t_link *inner;

	curr = start->link;
	while (curr)
	{
		inner = curr;
		while (inner)
		{
			if (inner->room->step > start->step + 1)
				inner->room->step = start->step + 1;
			inner = inner->next;
		}
		start->is_available = FALSE;
		if (curr->room->is_available)
			fill(curr->room);
		curr = curr->next;
	}
}

int			main(void)
{
	t_lemin	*lemin;

	lemin = create_lemin();
	if (!start_near_finish(lemin))
	{
		fill(lemin->finish);
		set_available(lemin->rooms, TRUE);
		run(lemin);
	}
	return (0);
}
