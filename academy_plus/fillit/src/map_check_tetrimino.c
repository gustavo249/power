/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_tetrimino.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:16:48 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 14:16:55 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int	map_check_tetrimino(t_map *map, t_trimino *tetrimino, int x, int y)
{
	int	i;
	int	cx;
	int	cy;

	cx = 0;
	cy = 0;
	i = 0;
	while (tetrimino->cases[i])
	{
		if (tetrimino->cases[i] == '#')
		{
			cx = (i % SIZE) + x;
			cy = (i / SIZE) + y;
			if (cx > map->target || cy > map->target)
				return (0);
			if ((map->cases[cx][cy] != '.') &&
				(map->cases[cx][cy] != tetrimino->color))
				return (0);
		}
		i++;
	}
	return (1);
}
