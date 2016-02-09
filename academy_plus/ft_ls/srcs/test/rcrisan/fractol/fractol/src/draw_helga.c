/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helga.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 14:39:38 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/16 23:44:46 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color_helga(t_env *e, float geom_x, float geom_y)
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
		z_x = z_x * z_x * z_x * z_x * z_x - 10 * z_x * z_x * z_x * z_y * z_y +
			5 * z_x * z_y * z_y * z_y * z_y + e->julia_x;
		z_y = 5 * aux * aux * aux * aux * z_y - 10 * aux * aux * z_y *
			z_y * z_y + z_y * z_y * z_y * z_y * z_y + e->julia_y;
		steps += e->step;
	}
	return (steps);
}

void	draw_helga(t_env *e)
{
	float	row;
	float	col;
	float	geom_x;
	float	geom_y;
	int		index;

	e->julia_x = -0.7 + e->move_x;
	e->julia_y = 0.27015 + e->move_y;
	index = 0;
	row = 0;
	while (row < WINDOW_HEIGHT)
	{
		col = 0;
		while (col < WINDOW_WIDTH)
		{
			geom_x = (col - e->origin_x) / 250;
			geom_y = (row - e->origin_y) / 250;
			put_pixel(e->string + index,
					get_color_helga(e, geom_x, geom_y), e->color);
			index += 4;
			col++;
		}
		row++;
	}
}
