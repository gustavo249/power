/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:00:38 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/29 19:21:49 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_struct(t_mod *data)
{
	data->rows = 0;
	data->cols = 0;
}

int		validate_content(char	*content)
{
	int i;

	i = 0;
	while (content[i])
	{
		if (!ft_isdigit(content[i]) && content[i] != '-')
			return (-1);
		i++;
	}
	return (1);
}

int		**add_new_content(int **new_matrix, char **row, t_mod *data, int *i)
{
	int j;
	int k;
	int p;

	p = *i;
	new_matrix[p] = (int*)malloc(sizeof(int) * data->cols);
	k = 0;
	j = 0;
	while (row[k])
	{
		new_matrix[p][j] = ft_atoi(row[k]);
		k++;
		j++;
	}
	return (new_matrix);
}

int		**add_new_row(int **matrix, char **row, t_mod *data)
{
	int		**new_matrix;
	int		i;
	int		k;
	int		j;

	i = 0;
	new_matrix = (int**)malloc(sizeof(int*) * data->rows);
	while (i < data->rows - 1)
	{
		new_matrix[i] = (int*)malloc(sizeof(int) * data->cols);
		j = 0;
		while (j < data->cols)
		{
			new_matrix[i][j] = matrix[i][j];	
			j++;
		}
		i++;
	}
	new_matrix = add_new_content(new_matrix, row, data, &i);
	return (new_matrix);
}

void	print_matrix(int	**matrix, t_mod *data)
{
	int i, j;

	for (i = 0; i < data->rows; i++)
	{
		for (j = 0; j < data->cols; j++)
			printf(" %d", matrix[i][j]);
		printf("\n");
	}
}

int		**add_first_row(t_mod *data, char **first_row, int fd, int **matrix)
{
	char	*line;

	get_next_line(fd, &line);

	if (line != NULL)
	{
		first_row = ft_strsplit(line, ' ');	
		while (first_row[data->cols] != '\0')
			data->cols++;
		data->rows++;

		matrix = add_new_row(matrix, first_row, data);
	}
	return (matrix);

}

int		read_matrix(int fd, t_mod *data)
{
	char	*line;
	char	**first_row;
	int		i;
	int		cols;
	int		**matrix;

	matrix = NULL;
	i = 0;
	cols = 0;
	if (data->error == 1)
		return (-1);
	matrix = add_first_row(data, first_row, fd, matrix);
	while (get_next_line(fd, &line))
	{
		cols = 0;
		first_row = ft_strsplit(line, ' ');
		while (first_row[cols] != '\0')
			cols++;
		if (cols != data->cols)
			return (-1);
		data->rows++;
		matrix = add_new_row(matrix ,first_row, data);
	}
	print_matrix(matrix, data);
	return (1);
}

int main (int argc, char **argv)
{
	t_mod	data;
	int		fd;

	if (argc != 2)
		return (-1);
	fd = open (argv[1], O_RDONLY);
	init_struct(&data);
	read_matrix(fd, &data);
	close(fd);
}
