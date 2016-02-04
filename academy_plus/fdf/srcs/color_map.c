/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:58:28 by rcrisan           #+#    #+#             */
/*   Updated: 2016/02/03 17:18:58 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_min_max_height(t_mod *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->m2[i][j].z > data->max_z)
				data->max_z = data->m2[i][j].z;
			if (data->m2[i][j].z < data->min_z)
				data->min_z = data->m2[i][j].z;
			j++;
		}
		i++;
	}
}

int		get_color(t_mod *data)
{
	int		v;
	float	height_size;

	height_size = data->max_z - data->min_z;
	v = height_size / HEIGHT * 255;
	data->white -= v - 10;
	return (data->white);
}

void	draw_line_axis(t_mod *data, t_point v, t_point v1)
{
	float	t;
	float	step;
	float	x;
	float	y;

	step = 1 / (fmax(fabs(v1.x - v.x), fabs(v1.y - v.y)));
	t = 0;
	while (t < 1)
	{
		x = v.x + t * (v1.x - v.x);
		y = v.y + t * (v1.y - v.y);
		mlx_pixel_put(data->mlx, data->win, x, y, get_color(data));
		t = t + step;
	}
}

void	draw_between_points(t_mod *data, t_point **matrix)
{
	int i;
	int j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (j < data->cols - 1)
				draw_line_axis(data, matrix[i][j], matrix[i][j + 1]);
			if (i < data->rows - 1)
				draw_line_axis(data, matrix[i][j], matrix[i + 1][j]);
			j++;
		}
		i++;
	}
}
