/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:50:53 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/22 17:09:02 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualization.h"
#include <mlx.h>

int		exit_x(void)
{
	exit(1);
	return (1);
}

void	fill_image(t_image *image, int x, int y, int rgb)
{
	if (x > 0 && x < FIELD_WIDTH && y > 0 && y < FIELD_HEIGHT)
		*(int *)(image->ptr + ((x + y * FIELD_WIDTH) * image->bpp)) = rgb;
}

void	draw_line(t_global *global, int p1[2], int p2[2], int color)
{
	int delta[2];
	int sign[2];
	int error[2];

	delta[X] = abs(p2[X] - p1[X]);
	delta[Y] = abs(p2[Y] - p1[Y]);
	sign[X] = p1[X] < p2[X] ? 1 : -1;
	sign[Y] = p1[Y] < p2[Y] ? 1 : -1;
	error[0] = delta[X] - delta[Y];
	fill_image(global->image, p2[X], p2[Y], color);
	while (p1[X] != p2[X] || p1[Y] != p2[Y])
	{
		fill_image(global->image, p1[X], p1[Y], color);
		error[1] = error[0] * 2;
		if (error[1] > -delta[Y])
		{
			error[0] -= delta[Y];
			p1[X] += sign[X];
		}
		if (error[1] < delta[X])
		{
			error[0] += delta[X];
			p1[Y] += sign[Y];
		}
	}
}

void	fill_image_fon(t_image *image, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < FIELD_HEIGHT)
	{
		j = -1;
		while (++j < FIELD_WIDTH)
			fill_image(image, j, i, color);
	}
}
