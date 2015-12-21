/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:17:59 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 14:18:01 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

t_map	*map_solve(t_map *map, t_trimino *tetriminos)
{
	map->target = ft_sqrt(tetrimino_count(tetriminos) * SIZE) - 1;
	while (recursive(map, tetriminos))
	{
		if (map->count < 0)
		{
			tetriminos = map->current;
			map->count = 0;
		}
		else
		{
			while (tetriminos->prev)
				tetriminos = tetriminos->prev;
			map_reset_tetriminos(map, tetriminos);
			map->target++;
		}
	}
	return (map);
}
