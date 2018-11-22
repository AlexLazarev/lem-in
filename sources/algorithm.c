/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:47:13 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 17:02:40 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_link		*find_min(t_room *room, t_link *inner)
{
	t_link	*min;

	min = create_link(room);
	while (inner)
	{
		if (inner->room->step < min->room->step &&
			inner->room->is_available)
			min->room = inner->room;
		inner = inner->next;
	}
	return (min);
}

t_link		*link_path(t_room *room)
{
	t_link	*path;
	t_link	*curr;
	t_link	*min;
	t_link	*begin;

	path = NULL;
	curr = create_link(room);
	begin = curr;
	while (curr->room->step)
	{
		min = find_min(room, curr->room->link);
		if (min->room == room)
		{
			free(begin);
			free(min);
			return (NULL);
		}
		link_push(&path, min);
		curr->room->is_available = FALSE;
		curr = min;
	}
	free(begin);
	return (path);
}

static int	live_away(t_link **ants, t_path *p)
{
	static int	count = 0;
	t_path		*path;

	path = p;
	while (path)
	{
		if (path->ant-- > 0)
		{
			ants[count] = path->link;
			count++;
		}
		path = path->next;
	}
	return (count);
}

void		print_ants(t_link **ants, t_lemin *lemin)
{
	int		live;
	int		i;
	int		away;

	live = 0;
	while (live < lemin->ant)
	{
		i = live;
		away = live_away(ants, lemin->paths);
		while (i < away)
		{
			if (ants[i]->room == lemin->finish)
				live = i + 1;
			if (ants[i])
			{
				ft_printf("L%d-%s", i + 1, ants[i]->room->name);
				if (i < away - 1)
					ft_printf(" ");
			}
			ants[i] = ants[i]->next;
			i++;
		}
		ft_printf("\n");
	}
}

void		run(t_lemin *lemin)
{
	t_link	**ants;
	int		i;

	ants = (t_link**)malloc(sizeof(t_link*) * (lemin->ant));
	i = -1;
	while (++i < lemin->ant)
		ants[i] = NULL;
	init_path(lemin);
	ft_putstr(lemin->info);
	ft_putchar('\n');
	print_ants(ants, lemin);
	free(ants);
}
