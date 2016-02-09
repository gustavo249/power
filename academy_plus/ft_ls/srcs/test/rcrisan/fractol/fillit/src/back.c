/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 22:42:05 by azaha             #+#    #+#             */
/*   Updated: 2016/01/04 14:10:56 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		back(char **mat, int n, int shapei)
{
	t_coord		c;

	c.i = 0;
	while (c.i < n)
	{
		c.j = 0;
		while (c.j < n)
		{
			g_cshape = shapei;
			if (put_shape(mat, c, n, g_shapes[shapei]))
			{
				if (shapei + 1 == count_shapes(g_shapes))
				{
					print_matrix(mat, n);
					exit(0);
				}
				if (count_spaces(mat, n) <= n * n - count_shapes(g_shapes) * 4)
					back(mat, n, shapei + 1);
			}
			g_cshape = shapei;
			clear_shape(mat, c, n, g_shapes[shapei]);
			c.j++;
		}
		c.i++;
	}
}
