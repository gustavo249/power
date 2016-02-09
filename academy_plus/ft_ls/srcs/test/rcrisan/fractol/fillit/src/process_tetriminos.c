/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_tetriminos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:59:53 by azaha             #+#    #+#             */
/*   Updated: 2016/01/04 12:12:20 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	check_tetriminos(char *tetriminos)
{
	int i;
	int hash;

	i = 0;
	hash = 0;
	if (ft_strlen(tetriminos) != 20)
		exit_program();
	while (tetriminos[i] != '\0')
	{
		if (tetriminos[i] == '#')
			hash++;
		i++;
	}
	if (hash != 4)
		exit_program();
}

static	void	check_and_free(char **matrix, char **aux, t_elem *anexe)
{
	if (anexe->hash != 4)
		exit_program();
	free(matrix);
	free(aux);
}

static	char	**allocate_matrix(int line, int col)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = (char**)malloc(sizeof(char*) * line + 1);
	while (i < line)
	{
		matrix[i] = ft_memalloc(col + 1);
		ft_memset(matrix[i], '0', col);
		i++;
	}
	matrix[i] = 0;
	return (matrix);
}

void			process_tetriminos(char **this_element, char *tetriminos)
{
	char	**aux;
	char	**matrix;
	t_elem	anexe;

	init_elem(&anexe);
	check_tetriminos(tetriminos);
	matrix = ft_strsplit(tetriminos, '*');
	aux = allocate_matrix(6, 6);
	*this_element = ft_memalloc(10);
	while (matrix[anexe.i] != 0)
	{
		anexe.j = 0;
		while (matrix[anexe.i][anexe.j] != '\0')
		{
			if (matrix[anexe.i][anexe.j] == '#')
			{
				aux[anexe.i + 1][anexe.j + 1] = '1';
				directions_back(this_element, matrix, aux, &anexe);
			}
			anexe.j++;
		}
		anexe.i++;
	}
	check_and_free(matrix, aux, &anexe);
}
