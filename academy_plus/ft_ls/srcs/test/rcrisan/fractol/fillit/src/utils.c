/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 21:52:15 by azaha             #+#    #+#             */
/*   Updated: 2016/01/13 16:30:21 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_shapes(char **shapes)
{
	int		count;

	count = 0;
	while (shapes[count])
		count++;
	return (count);
}

char	**create_matrix(int n)
{
	int		index;
	char	**result;

	result = (char**)malloc(sizeof(char*) * n);
	index = 0;
	while (index < n)
		result[index++] = (char*)malloc(n);
	return (result);
}

void	init_matrix(char **mat, int n)
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			mat[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	print_matrix(char **mat, int n)
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			ft_putchar(mat[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
