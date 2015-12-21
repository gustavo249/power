/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:19:41 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 14:19:42 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int	tetrimino_pos(t_trimino *tetrimino)
{
	int			pos;
	t_trimino	*tmp;

	pos = -1;
	tmp = tetrimino;
	while (tmp)
	{
		pos++;
		tmp = tmp->prev;
	}
	return (pos);
}
