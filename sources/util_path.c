/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:03:16 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 17:03:42 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include "../includes/error.h"

void	delete_path(t_path **begin, t_path **path)
{
	t_path	*curr;

	curr = *begin;
	if (path && *path)
	{
		if (*begin != *path)
		{
			while (curr && curr->next != *path)
				curr = curr->next;
			if (curr->next == *path)
				curr->next = (*path)->next;
		}
		else
			*begin = (*begin)->next;
		free(*path);
	}
}

t_path	*create_path(t_link *link)
{
	t_path	*path;

	path = (t_path*)malloc(sizeof(t_path));
	path->link = link;
	path->ant = 0;
	path->next = NULL;
	return (path);
}

t_path	*find_path(t_path *path)
{
	t_path	*min;

	min = path;
	while (path)
	{
		if (path->ant + path->size < min->ant + min->size)
			min = path;
		path = path->next;
	}
	return (min);
}

void	path_push(t_path **begin, t_path *new)
{
	t_path	*cur;

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

void	init_path(t_lemin *lemin)
{
	t_link	*link;
	t_path	*path;
	int		i;

	if (!(link = link_path(lemin->start)))
		error(ERROR_PATH);
	while (link)
	{
		path = create_path(link);
		path->size = get_link_len(link);
		path->ant = 0;
		path->next = NULL;
		path_push(&lemin->paths, path);
		link = link_path(lemin->start);
	}
	i = 0;
	while (i < lemin->ant)
	{
		path = find_path(lemin->paths);
		path->ant++;
		i++;
	}
}
