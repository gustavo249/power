/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:18:01 by azaha             #+#    #+#             */
/*   Updated: 2016/01/12 15:51:04 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	**allocate_points(int rows, int columns)
{
	t_point	**map;
	int		index;

	index = 0;
	map = (t_point**)malloc(sizeof(t_point*) * rows);
	while (index < rows)
	{
		map[index] = (t_point*)malloc(sizeof(t_point) * columns);
		index++;
	}
	return (map);
}
