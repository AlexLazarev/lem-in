/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:21:56 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 16:35:03 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include "../includes/error.h"

static void	init_lemin(t_lemin *lemin)
{
	char	*buf;
	int		flag;

	flag = ANT_INIT;
	while (get_next_line(0, &buf) > 0)
	{
		if (!*buf || *buf == '\n')
		{
			if (flag < ROOM_COMPLETE)
				error(ERROR_INPUT);
			break ;
		}
		init_info(lemin, buf);
		if (!is_comment(buf))
		{
			if (flag == ANT_INIT)
				flag = init_ants(lemin, buf);
			else if (flag == ANT_COMPLETE)
				flag = init_rooms(lemin, buf);
			if (flag == ROOM_COMPLETE)
				init_links(lemin, buf);
		}
		free(buf);
	}
	free(buf);
}

t_lemin		*create_lemin(void)
{
	t_lemin	*lemin;

	lemin = (t_lemin*)malloc(sizeof(t_lemin));
	lemin->info = ft_strnew(0);
	lemin->rooms = NULL;
	lemin->paths = NULL;
	lemin->ant = 0;
	lemin->start = NULL;
	lemin->finish = NULL;
	init_lemin(lemin);
	if (!lemin->start || !lemin->finish)
		error(ERROR_INPUT);
	lemin->finish->step = 0;
	return (lemin);
}
