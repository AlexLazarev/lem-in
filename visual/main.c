/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:09:15 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 17:09:58 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualization.h"
#include <mlx.h>

int			main(void)
{
	t_global	*global;

	global = (t_global*)malloc(sizeof(t_global));
	global->mlx = mlx_init();
	global->window = mlx_new_window(global->mlx,
									WINDOW_WIDTH, WINDOW_HEIGHT, "LEM-IN");
	global->image = (t_image*)malloc(sizeof(t_image));
	global->image->img = mlx_new_image(global->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	global->image->ptr = mlx_get_data_addr(global->image->img,
			&global->image->bpp,
			&global->image->size_line, &global->image->endian);
	global->image->bpp /= 8;
	init_rooms(global);
	if (global->start)
		global->start->id_ant = -1;
	fill_image_fon(global->image, 0x4D4D4D);
	draw(global);
	mlx_hook(global->window, 17, 0, exit_x, NULL);
	mlx_hook(global->window, 2, 0, deal_key, global);
	mlx_loop(global->mlx);
	return (0);
}
