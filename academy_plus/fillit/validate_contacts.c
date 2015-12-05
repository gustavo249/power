/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 10:27:02 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/05 14:08:48 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		validate_corners(char **matrix)
{
	int i;
	int j;

	i = 0;
	while (i++ < 4)
	{
		j = 0;
		while (j++ < 5)
		{
			if (matrix[i][j] == '#' && i == 0 && j == 0)
				if (matrix[i + 1][j] != '#' && matrix[i][j + 1] != '#')
					return (0);
			if (matrix[i][j] == '#' && i == 3 && j == 0)
				if (matrix[i - 1][j] != '#' && matrix[i][j + 1] != '#')
					return (0);
		}
	}
	return (1);
}

int		validate_matrix_lines(char **matrix)
{
	int i;
	int j;

	i = 0;
	while (i++ < 4)
	{
		j = 0;
		while (j++ < 5)
		{
			if ((matrix[i][j] == '#' && j > 0 && j < 4) && (i == 1 || i == 2))
				if (matrix[i][j - 1] != '#' && matrix[i][j + 1] != '#' && \
						matrix[i - 1][j] != '#' && matrix[i + 1][j] != '#')
					return (0);
			if (matrix[i][j] == '#' && i == 0 && j > 0 && j < 4)
				if (matrix[i + 1][j] != '#' && matrix[i][j + 1] != '#' && \
						matrix[i][j - 1] != '#')
					return (0);
			if (matrix[i][j] == '#' && i == 3 && j > 0 && j < 4)
				if (matrix[i - 1][j] != '#' && matrix[i][j + 1] != '#' && \
						matrix[i][j - 1] != '#')
					return (0);
		}
	}
	return (1);
}
