/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reset_tetriminos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:17:48 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 14:17:50 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	map_reset_tetriminos(t_map *map, t_trimino *tetriminos)
{
	t_trimino	*current;

	current = tetriminos;
	while (current)
	{
		map_unprint_tetrimino(map, current);
		tetriminos->x = -1;
		tetriminos->y = -1;
		current = current->next;
	}
}
