/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 21:31:18 by azaha             #+#    #+#             */
/*   Updated: 2016/01/13 16:56:38 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_env(t_env *e, int argc, char **argv)
{
	e->map_config = (t_map_config*)malloc(sizeof(t_map_config));
	if (argc != 2)
		exit_program();
	e->file = argv[1];
	get_rows_and_columns(e);
	e->map = allocate_points(e->map_config->rows, e->map_config->columns);
	get_coordinates(e);
	get_max_and_min_height(e);
	get_color_scale(e);
	e->map_config->step = get_step(e->map_config->rows, e->map_config->columns);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGHT, get_name(e->file));
	reset_configuration(e);
}
