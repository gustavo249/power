/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:17:09 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 14:17:12 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

t_map	*map_dup(t_map *map)
{
	t_map	*bestmap;
	int		x;
	int		y;

	x = 0;
	y = 0;
	bestmap = map_new();
	while (x < MAX * SIZE)
	{
		y = 0;
		while (y < MAX * SIZE)
		{
			bestmap->cases[x][y] = map->cases[x][y];
			y++;
		}
		x++;
	}
	return (bestmap);
}
