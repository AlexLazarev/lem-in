/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:20:24 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 17:04:02 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include "../includes/error.h"

int		is_comment(char *buf)
{
	return (*buf == '#' && ft_strcmp(buf, START) && ft_strcmp(buf, FINISH));
}

void	init_info(t_lemin *lemin, char *buf)
{
	char *index;

	index = lemin->info;
	lemin->info = ft_strjoin(lemin->info, buf);
	free(index);
	index = lemin->info;
	lemin->info = ft_strjoin(lemin->info, "\n");
	free(index);
}

void	error(int e)
{
	if (e == ERROR_ANT_SIZE)
		ft_printf(" hmm, ants are absent\n");
	else if (e == ERROR_ROOM)
		ft_printf(" Bad input format in field 'room'\n");
	else if (e == ERROR_ROOM_POS)
		ft_printf(" Some trouble with position\n");
	else if (e == ERROR_ROOM_NAME)
		ft_printf(" Some trouble with name!\n");
	else if (e == ERROR_LINK_NAME)
		ft_printf(" hm... There is no such room!\n");
	else if (e == ERROR_LINK)
		ft_printf(" Bad input format in field 'link'\n");
	else if (e == ERROR_ROOM_START)
		ft_printf(" Come on, where is start?\n");
	else if (e == ERROR_ROOM_FINISH)
		ft_printf(" Come on, where is finish?\n");
	else if (e == ERROR_ONLY_ONE_START)
		ft_printf(" ONLY ONE START! Not more!!!\n");
	else if (e == ERROR_ONLY_ONE_FINISH)
		ft_printf(" ONLY ONE FINISH! Not more!!!\n");
	else if (e == ERROR_INPUT)
		ft_printf(" And what should I read??\n");
	else if (e == ERROR_PATH)
		ft_printf(" <PANIC> We haven't path!!!\n");
	exit(1);
}

int		start_near_finish(t_lemin *lemin)
{
	t_link	*link;
	int		i;

	link = lemin->start->link;
	while (link)
	{
		if (link->room == lemin->finish)
		{
			ft_putstr(lemin->info);
			ft_putchar('\n');
			i = 1;
			while (i <= lemin->ant)
			{
				ft_printf("L%d-%s", i++, lemin->finish->name);
				if (i <= lemin->ant)
					ft_printf(" ");
			}
			ft_printf("\n");
			return (1);
		}
		link = link->next;
	}
	return (0);
}

void	set_available(t_link *link, int state)
{
	while (link)
	{
		link->room->is_available = state;
		link = link->next;
	}
}
