/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_and_min_height.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 10:44:26 by azaha             #+#    #+#             */
/*   Updated: 2016/01/13 11:14:44 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_max_and_min_height(t_env *e)
{
	int		row;
	int		column;
	float	min;
	float	max;

	row = 0;
	min = e->map[0][0].z;
	max = e->map[0][0].z;
	while (row < e->map_config->rows)
	{
		column = 0;
		while (column < e->map_config->columns)
		{
			if (e->map[row][column].z < min)
				min = e->map[row][column].z;
			if (e->map[row][column].z > max)
				max = e->map[row][column].z;
			column++;
		}
		row++;
	}
	e->map_config->max_height = max;
	e->map_config->min_height = min;
}
