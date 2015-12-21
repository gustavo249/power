/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:52:50 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/05 14:40:50 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	fill(char *str, char **matrix)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[k])
	{
		while (i < 4)
		{
			j = 0;
			while (j < 5)
			{
				matrix[i][j] = str[k];
				j++;
				k++;
			}
			i++;
		}
		k++;
	}
}

char	**create_matrix(char *str)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = (char**)malloc(sizeof(char*) * 5);
	while (i < 5)
	{
		matrix[i] = (char*)malloc(sizeof(char) * 5);
		i++;
	}
	fill(str, matrix);
	return (matrix);
}
