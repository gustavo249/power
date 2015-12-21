/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:14:04 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 14:18:29 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static int	find_next_pos(t_map *map, t_trimino *t)
{
	int	x;
	int	y;

	if (t->x >= 0 && t->y >= 0)
	{
		x = t->x;
		y = t->y;
	}
	else
	{
		x = 0;
		y = 0;
	}
	while (y <= map->target)
	{
		x = 0;
		while (x <= map->target)
		{
			if (map_check_tetrimino(map, t, x, y) && (t->x < x || t->y < y))
				return (map_print_tetrimino(map, t, x, y));
			x++;
		}
		y++;
	}
	return (0);
}

static int	protect_stack(t_map *map, t_trimino *tetrimino)
{
	map->count++;
	if (map->count > 20)
	{
		map->count = -1;
		map->current = tetrimino;
		return (1);
	}
	else
		return (0);
}

int			recursive(t_map *map, t_trimino *tetrimino)
{
	int	newpos;

	if (protect_stack(map, tetrimino))
		return (1);
	newpos = find_next_pos(map, tetrimino);
	if (newpos)
	{
		if (newpos <= map->target)
		{
			if (tetrimino->next)
				return (recursive(map, tetrimino->next));
		}
		else
			return (recursive(map, tetrimino));
	}
	else if (tetrimino->prev)
	{
		map_unprint_tetrimino(map, tetrimino);
		return (recursive(map, tetrimino->prev));
	}
	else if (!tetrimino->prev)
		return (1);
	return (0);
}
