/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_mapsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 13:06:37 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/05 15:20:37 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		validate_content(char **matrix)
{
	int i;
	int j;
	int hashtags;
	int points;

	i = 0;
	j = 0;
	points = 0;
	hashtags = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			if (matrix[i][j] == '#')
				hashtags++;
			else if (matrix[i][j] != '.' && matrix[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	if (hashtags != 4)
		return (0);
	return (1);
}
