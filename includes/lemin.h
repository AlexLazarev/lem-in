/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:26:56 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 17:51:17 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEMIN_H
# define _LEMIN_H

# include "../lib/libft/includes/ft_printf.h"
# include "../lib/libft/includes/get_next_line.h"

# define TRUE 1
# define FALSE 0

# define MAX_VALUE 30000
# define START "##start"
# define FINISH "##end"
# define ANT_COMPLETE 1
# define ROOM_COMPLETE 2
# define ROOM_IN_PROCESS 1
# define ANT_INIT 0

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_link
{
	struct s_room	*room;
	struct s_link	*next;
}				t_link;

typedef struct	s_room
{
	char	*name;
	int		is_available;
	int		step;
	t_point	pos;
	t_link	*link;
}				t_room;

typedef struct	s_path
{
	int				ant;
	size_t			size;
	t_link			*link;
	struct s_path	*next;
}				t_path;

typedef struct	s_lemin
{
	t_room	*start;
	t_room	*finish;
	t_link	*rooms;
	t_path	*paths;
	int		ant;
	char	*info;
}				t_lemin;

int				is_comment(char	*buf);
void			link_push(t_link **begin, t_link *new);
t_lemin			*create_lemin();
t_link			*create_link(t_room *room);
t_room			*find_room(t_link *link, char	*name);
t_room			*find_room_by_pos(t_link *link, t_point pos);
void			error(int e);
void			valid(t_lemin *lemin);
void			init_info(t_lemin *lemin, char *buf);
char			**valid_room(t_lemin *lemin, char *buf);
int				valid_ant(char *buf);
char			**valid_link(t_lemin *lemin, char *buf);
int				init_ants(t_lemin *lemin, char *buf);
void			init_links(t_lemin *lemin, char *buf);
int				init_rooms(t_lemin *lemin, char *buf);
void			init_sf(t_lemin *lemin, char *str);
t_room			*create_room(t_lemin *lemin, char	*buf);
void			run(t_lemin *lemin);
t_path			*create_path(t_link *link);
void			path_push(t_path **begin, t_path *new);
size_t			get_link_len(t_link *link);
t_path			*find_path(t_path *path);
t_link			*link_path(t_room	*room);
void			delete_path(t_path **begin, t_path **path);
int				start_near_finish(t_lemin *lemin);
void			set_available(t_link *link, int state);
void			init_path(t_lemin *lemin);
#endif
