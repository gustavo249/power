/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_unprint_tetrimino.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:13:56 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 14:18:15 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	map_unprint_tetrimino(t_map *map, t_trimino *tetrimino)
{
	int	x;
	int	y;

	if (tetrimino->x >= 0 && tetrimino->y >= 0)
	{
		x = tetrimino->x;
		y = tetrimino->y;
		while (x < (tetrimino->x + SIZE) && (x < SIZE * MAX))
		{
			while (y < (tetrimino->y + SIZE) && (y < SIZE * MAX))
			{
				if (map->cases[x][y] == tetrimino->color)
					map->cases[x][y] = '.';
				else
					y++;
			}
			y = tetrimino->y;
			x++;
		}
		tetrimino->x = -1;
		tetrimino->y = -1;
		map->min = 0;
	}
}
