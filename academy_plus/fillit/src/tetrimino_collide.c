/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_collide.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:19:08 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 14:19:10 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static int	tetrimino_case_check(t_trimino *tetrimino, int x, int y)
{
	if (tetrimino->cases[x + (y * SIZE)] == '.')
		return (0);
	return (1);
}

static int	tetrimino_case_collide(t_trimino *tetrimino, int x, int y)
{
	int	collide;

	collide = 0;
	if (y < SIZE - 1)
		if (tetrimino_case_check(tetrimino, x, y + 1))
			collide++;
	if (y > 0)
		if (tetrimino_case_check(tetrimino, x, y - 1))
			collide++;
	if (x < SIZE - 1)
		if (tetrimino_case_check(tetrimino, x + 1, y))
			collide++;
	if (x > 0)
		if (tetrimino_case_check(tetrimino, x - 1, y))
			collide++;
	return (collide);
}

void		tetrimino_check_collide(t_trimino *tetrimino)
{
	int	collide;
	int	i;

	i = 0;
	collide = 0;
	while (tetrimino->cases[i])
	{
		if (tetrimino_case_check(tetrimino, i % SIZE, i / SIZE))
			collide += tetrimino_case_collide(tetrimino, i % SIZE, i / SIZE);
		i++;
	}
	if (collide != 6 && collide != 8)
		error();
}
