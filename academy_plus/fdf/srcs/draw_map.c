/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:10:46 by rcrisan           #+#    #+#             */
/*   Updated: 2016/02/03 17:12:41 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_mod *data)
{
	t_point **matrix;

	data->m2 = get_initial_coords(data);
	get_min_max_height(data);
	transform_all_points_relative_to_map_center(data);
	control_height(data);
	matrix = get_isometric_coords(data);
	draw_between_points(data, matrix);
}

int		key_hook(int keycode, t_mod *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (keycode == 126)
	{
		modify_z(data, 1);
		draw_matrix(data);
	}
	else if (keycode == 125)
	{
		modify_z(data, -1);
		draw_matrix(data);
	}
	return (0);
}

void	get_size(t_mod *data)
{
	if (data->cols > 100)
		data->line_size = (WIDTH - 300) / data->cols;
	else
		data->line_size = (WIDTH - 600) / data->cols;
}

int		draw_matrix(t_mod *data)
{
	get_size(data);
	draw(data);
	show_usage(data);
	return (0);
}

void	draw_map(t_mod *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "win");
	mlx_expose_hook(data->win, draw_matrix, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
	sleep(10);
}
