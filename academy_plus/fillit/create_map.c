/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:52:50 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/04 19:25:58 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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
	int i;
	char **matrix;

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

int		validate_matrix(char **matrix)
{
	int i;
	int j;

	i = 0;
	j = 0;
	
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			if (matrix[i][j] == '#' && j >= 1 && j <= 3 && i == 1 || i == 2)
				if (matrix[i][j - 1] != '#' && matrix[i][j + 1] != '#' \
						&& matrix[i - 1][j] != '#' && matrix[i + 1][j] != '#')
					return (0);
		}
	}
		i++;
	}
	return (1);
}

int main ()
{
	char *str;
	char **matrix;
	int i = 0;
	int j = 0;

	str = "....\n..##\n..#.\n..#.\n\n";
	matrix = create_matrix(str);
	while (i <= 4)
	{
		j = 0;
		while (j < 5)
		{
			printf("%c", matrix[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}
