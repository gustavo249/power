/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 22:48:18 by azaha             #+#    #+#             */
/*   Updated: 2016/01/11 10:37:53 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw(t_env *e)
{
	int		row;
	int		column;
	t_point	**point;
	t_point	mid;

	point = e->map;
	row = 0;
	mid.w_x = WIN_WIDTH / 2;
	mid.w_y = WIN_HEIGHT / 2;
	while (row < e->map_config->rows)
	{
		column = 0;
		while (column < e->map_config->columns)
		{
			if (row < e->map_config->rows - 1)
				draw_line(e, point[row][column], point[row + 1][column]);
			if (column < e->map_config->columns - 1)
				draw_line(e, point[row][column], point[row][column + 1]);
			column++;
		}
		row++;
	}
}
