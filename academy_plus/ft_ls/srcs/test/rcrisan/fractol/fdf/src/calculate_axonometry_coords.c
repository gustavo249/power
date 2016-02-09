/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_axonometry_coords.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:26:29 by azaha             #+#    #+#             */
/*   Updated: 2016/01/13 10:52:10 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	float	calculate_x(float step, t_point point)
{
	float x;

	x = WIN_WIDTH / 2 + step * point.x - step * point.y;
	return (x);
}

static	float	calculate_y(float hs, float step, t_point point)
{
	float y;

	y = WIN_HEIGHT / 2 + 0.5 * step * point.x + step * point.y -
		0.1 * step * point.z * hs;
	return (y);
}

static	void	zoom_map(t_env *e)
{
	int	row;
	int	column;

	row = 0;
	while (row < e->map_config->rows)
	{
		column = 0;
		while (column < e->map_config->columns)
		{
			e->map[row][column].w_x = WIN_WIDTH / 2 +
				(e->map[row][column].w_x - WIN_WIDTH / 2) *
				e->map_config->zoom;
			e->map[row][column].w_y = WIN_HEIGHT / 2 +
				(e->map[row][column].w_y - WIN_HEIGHT / 2) *
				e->map_config->zoom;
			column++;
		}
		row++;
	}
}

static	void	translate_map(t_env *e)
{
	int	row;
	int	column;

	row = 0;
	while (row < e->map_config->rows)
	{
		column = 0;
		while (column < e->map_config->columns)
		{
			e->map[row][column].w_x += e->map_config->x_offset;
			e->map[row][column].w_y += e->map_config->y_offset;
			column++;
		}
		row++;
	}
}

void			calculate_axonometry_coords(t_env *e)
{
	int	row;
	int	column;

	row = 0;
	while (row < e->map_config->rows)
	{
		column = 0;
		while (column < e->map_config->columns)
		{
			e->map[row][column].w_x =
				calculate_x(e->map_config->step, e->map[row][column]);
			e->map[row][column].w_y =
				calculate_y(e->map_config->height_scale, e->map_config->step,
						e->map[row][column]);
			column++;
		}
		row++;
	}
	translate_map(e);
	zoom_map(e);
}
