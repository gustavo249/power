/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 11:51:01 by azaha             #+#    #+#             */
/*   Updated: 2016/01/13 13:46:41 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_color_scale(t_env *e)
{
	int		row;
	int		column;

	row = 0;
	while (row < e->map_config->rows)
	{
		column = 0;
		while (column < e->map_config->columns)
		{
			e->map[row][column].color_scale = 255 - 255 *
				(e->map[row][column].z - e->map_config->min_height) /
				(e->map_config->max_height - e->map_config->min_height);
			column++;
		}
		row++;
	}
}
