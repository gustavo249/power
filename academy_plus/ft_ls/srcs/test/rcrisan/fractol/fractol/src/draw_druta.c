/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_druta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 22:29:59 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/16 23:37:37 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color_druta(t_env *e, float geom_x, float geom_y)
{
	int		steps;
	float	z_x;
	float	z_y;
	float	aux;

	steps = 0;
	z_x = geom_x;
	z_y = geom_y;
	while (steps < MAX_STEPS && z_x * z_x + z_y * z_y <= 4)
	{
		aux = z_x;
		z_x = z_x * z_x * z_x - 3 * z_x * z_y * z_y + geom_x;
		z_y = 3 * aux * aux * z_y - z_y * z_y * z_y + geom_y;
		steps += e->step;
	}
	return (steps);
}

void	draw_druta(t_env *e)
{
	float	row;
	float	col;
	float	geom_x;
	float	geom_y;
	int		index;

	index = 0;
	row = 0;
	while (row < WINDOW_HEIGHT)
	{
		col = 0;
		while (col < WINDOW_WIDTH)
		{
			geom_x = (col - e->origin_x) / e->zoom;
			geom_y = (row - e->origin_y) / e->zoom;
			put_pixel(e->string + index,
					get_color_druta(e, geom_x, geom_y), e->color);
			index += 4;
			col++;
		}
		row++;
	}
}
