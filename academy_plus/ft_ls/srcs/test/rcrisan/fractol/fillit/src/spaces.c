/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 22:47:02 by azaha             #+#    #+#             */
/*   Updated: 2015/12/23 22:47:05 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fillit.h"

static void			init_viz(void)
{
	int		i;
	int		j;

	i = 0;
	while (i < 13)
	{
		j = 0;
		while (j < 13)
		{
			g_viz[i][j] = 0;
			j++;
		}
		i++;
	}
}

static int			check_free(char **mat, int i, int j, int n)
{
	if (i < 0 || i > n || j < 0 || j > n || mat[i][j] != '.')
	{
		return (0);
	}
	return (1);
}

static int			lee(char **mat, int i, int j, int n)
{
	if (i < 0 || i > n || j < 0 || j > n || g_viz[i][j])
		return (0);
	if (check_free(mat, i, j, n))
	{
		g_viz[i][j] = 1;
		return (1 + lee(mat, i + 1, j, n) +
				lee(mat, i - 1, j, n) +
				lee(mat, i, j + 1, n) +
				lee(mat, i, j - 1, n));
	}
	return (0);
}

int					count_spaces(char **mat, int n)
{
	int		i;
	int		j;
	int		result;
	int		tmp;

	result = 0;
	i = 0;
	init_viz();
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			tmp = 0;
			if (mat[i][j] == '.' && !g_viz[i][j])
				tmp = lee(mat, i, j, n);
			if (tmp <= 3)
				result += tmp;
			j++;
		}
		i++;
	}
	return (result);
}
