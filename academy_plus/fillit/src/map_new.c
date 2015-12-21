/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:17:20 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 14:17:22 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

t_map	*map_new(void)
{
	int		x;
	t_map	*map;

	x = 0;
	map = (t_map*)malloc(sizeof(t_map));
	map->cases = malloc(sizeof(char*) * (MAX * SIZE + 4));
	while (x < (MAX * SIZE))
	{
		map->cases[x] = ft_memalloc(MAX * SIZE + 4);
		ft_bzero(map->cases[x], (MAX * SIZE + 4));
		map->cases[x] = (char*)ft_memset(map->cases[x], '.', MAX * SIZE);
		x++;
	}
	map->cases[x] = ft_memalloc(MAX * SIZE + 4);
	ft_bzero(map->cases[x], MAX * SIZE + 4);
	map->count = 0;
	return (map);
}
