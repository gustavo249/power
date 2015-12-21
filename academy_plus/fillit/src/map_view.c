/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:18:21 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 14:18:22 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	map_view(t_map *map)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y < map->target + 1)
	{
		while (x < map->target + 1)
		{
			ft_putchar(map->cases[x][y]);
			x++;
		}
		y++;
		ft_putchar('\n');
		x = 0;
	}
}
