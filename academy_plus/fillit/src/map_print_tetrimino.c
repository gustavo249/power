/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print_tetrimino.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:17:29 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 14:17:31 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void	map_fix_min(t_map *map, int x, int y)
{
	int min;

	min = 0;
	if (x > y)
		min = x;
	else
		min = y;
	if (map->min < min)
		map->min = min;
}

int			map_print_tetrimino(t_map *map, t_trimino *tetrimino, int x, int y)
{
	int	i;
	int	pos;

	i = 0;
	pos = tetrimino_pos(tetrimino);
	if (map_check_tetrimino(map, tetrimino, x, y))
	{
		map_unprint_tetrimino(map, tetrimino);
		tetrimino->x = x;
		tetrimino->y = y;
		while (tetrimino->cases[i])
		{
			if (tetrimino->cases[i] == '#')
			{
				map->cases[(i % SIZE) + x][(i / SIZE) + y] = 'A' + pos;
				map_fix_min(map, (i % SIZE) + x, (i / SIZE) + y);
				tetrimino->color = ('A' + pos);
			}
			i++;
		}
		return (map->min);
	}
	else
		return (0);
}
