/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:11:43 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 17:51:32 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_VISUALIZATION_H
# define FILLER_VISUALIZATION_H

# include "../lib/libft/includes/ft_printf.h"
# include "../lib/libft/includes/get_next_line.h"

# define KEY_ESC 53
# define KEY_SPACE 49
# define KEY_N 45
# define KEY_M 46

# define WINDOW_WIDTH 2600
# define WINDOW_HEIGHT 1600
# define FIELD_WIDTH 2600
# define FIELD_HEIGHT 1600
# define ROOM_SIZE 60
# define X 0
# define Y 1
# define ALPHA 3
# define R 2
# define G 1
# define B 0
# define PADDING 5
# define START "##start"
# define FINISH "##end"

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef union	u_rgb
{
	int				rgba;
	unsigned char	c[4];
}				t_rgb;

typedef struct	s_image
{
	void			*img;
	char			*ptr;
	int				bpp;
	int				size_line;
	int				endian;
}				t_image;

typedef struct	s_link
{
	struct s_room	*room;
	struct s_link	*next;
}				t_link;

typedef struct	s_room
{
	char	*name;
	int		id_ant;
	t_point	pos;
	t_link	*link;
}				t_room;

typedef struct	s_global
{
	void			*mlx;
	t_image			*image;
	void			*window;
	t_link			*rooms;
	t_room			*start;
	t_room			*finish;
}				t_global;

void			fill_image(t_image *image, int x, int y, int rgb);
int				exit_x(void);
void			faq(t_global *global);
int				deal_key(int key, t_global *global);
t_link			*create_link(t_room *room);
void			link_push(t_link **begin, t_link *new);
t_room			*create_room(char	*buf);
void			init_rooms(t_global *global);
t_room			*find_room(t_link *link, char	*name);
int				draw(t_global *global);
void			init_links(t_global *global, char *buf);
void			draw_pixel(t_global *global, int x, int y, int color);
void			draw_line(t_global *global, int p1[2], int p2[2], int color);
void			info(t_global *global);
void			push_ant_in_room(t_link	*link, char *buf);
int				draw(t_global *global);
void			fill_image_fon(t_image *image, int color);
#endif
