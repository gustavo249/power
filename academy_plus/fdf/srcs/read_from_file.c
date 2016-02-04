/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:51:03 by rcrisan           #+#    #+#             */
/*   Updated: 2016/02/03 16:54:24 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_struct(t_mod *data)
{
	data->rows = 0;
	data->cols = 0;
	data->error = 0;
	data->min_z = 0;
	data->max_z = 0;
	data->white = 0xFF0000;
}

int		**add_new_content(int **new_matrix, t_mod *data, int *i)
{
	int j;
	int k;
	int p;

	p = *i;
	new_matrix[p] = (int*)malloc(sizeof(int) * data->cols);
	k = 0;
	j = 0;
	while (data->content[k])
	{
		new_matrix[p][j] = ft_atoi(data->content[k]);
		k++;
		j++;
	}
	return (new_matrix);
}

int		**add_new_row(t_mod *data)
{
	int		**new_matrix;
	int		i;
	int		j;

	i = 0;
	new_matrix = (int**)malloc(sizeof(int*) * data->rows);
	while (i < data->rows - 1)
	{
		new_matrix[i] = (int*)malloc(sizeof(int) * data->cols);
		j = 0;
		while (j < data->cols)
		{
			new_matrix[i][j] = data->matrix[i][j];
			j++;
		}
		i++;
	}
	new_matrix = add_new_content(new_matrix, data, &i);
	return (new_matrix);
}

int		**add_first_row(t_mod *data, int fd)
{
	char	*line;

	get_next_line(fd, &line);
	if (line != NULL)
	{
		data->content = ft_strsplit(line, ' ');
		while (data->content[data->cols] != '\0')
			data->cols++;
		data->rows++;
		data->matrix = add_new_row(data);
	}
	else
		data->error = 1;
	return (data->matrix);
}

int		read_matrix(int fd, t_mod *data)
{
	char	*line;
	int		i;
	int		cols;

	data->matrix = NULL;
	i = 0;
	cols = 0;
	data->matrix = add_first_row(data, fd);
	if (data->error == 1)
		return (-1);
	while (get_next_line(fd, &line))
	{
		cols = 0;
		data->content = ft_strsplit(line, ' ');
		while (data->content[cols] != '\0')
			cols++;
		if (cols != data->cols)
			return (-1);
		data->rows++;
		data->matrix = add_new_row(data);
	}
	return (1);
}
