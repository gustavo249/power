/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 14:40:58 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/16 23:30:30 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color_mandelbrot(t_env *e, float geom_x, float geom_y)
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
		z_x = z_x * z_x - z_y * z_y + geom_x;
		z_y = 2 * aux * z_y + geom_y;
		steps += e->step;
	}
	return (steps);
}

void	draw_mandelbrot(t_env *e)
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
					get_color_mandelbrot(e, geom_x, geom_y), e->color);
			index += 4;
			col++;
		}
		row++;
	}
}
