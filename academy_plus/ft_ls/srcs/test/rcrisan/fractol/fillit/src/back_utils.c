/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 21:52:29 by azaha             #+#    #+#             */
/*   Updated: 2015/12/23 22:46:16 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	move(char *shape, t_coord *c, int step)
{
	if (shape[step] == 'U')
		c->i--;
	else if (shape[step] == 'D')
		c->i++;
	else if (shape[step] == 'L')
		c->j--;
	else if (shape[step] == 'R')
		c->j++;
}

int			put_shape(char **mat, t_coord c, int n, char *shape)
{
	int		step;
	char	letter;

	step = 0;
	letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[g_cshape];
	if (mat[c.i][c.j] != '.')
		return (0);
	mat[c.i][c.j] = letter;
	while (shape[step])
	{
		move(shape, &c, step);
		if (c.i >= 0 && c.i < n && c.j >= 0 && c.j < n &&
				(mat[c.i][c.j] == '.' || mat[c.i][c.j] == letter))
			mat[c.i][c.j] = letter;
		else
			return (0);
		step++;
	}
	return (1);
}

int			clear_shape(char **mat, t_coord c, int n, char *shape)
{
	int		step;
	char	letter;

	step = 0;
	letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[g_cshape];
	if (mat[c.i][c.j] == letter)
		mat[c.i][c.j] = '.';
	while (shape[step])
	{
		if (shape[step] == 'U')
			c.i--;
		else if (shape[step] == 'D')
			c.i++;
		else if (shape[step] == 'L')
			c.j--;
		else if (shape[step] == 'R')
			c.j++;
		if (c.i >= 0 && c.i < n && c.j >= 0 && c.j < n &&
				mat[c.i][c.j] == letter)
			mat[c.i][c.j] = '.';
		step++;
	}
	return (1);
}
