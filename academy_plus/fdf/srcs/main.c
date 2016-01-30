/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:00:38 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/30 14:48:02 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_struct(t_mod *data)
{
	data->rows = 0;
	data->cols = 0;
	data->error = 0;
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
			new_matrix[i][j] = data->matrix[i][j];	
			j++;
		}
		i++;
	}
	new_matrix = add_new_content(new_matrix, data, &i);
	return (new_matrix);
}

void	print_matrix(t_mod *data)
{
	int i, j;

	for (i = 0; i < data->rows; i++)
	{
		for (j = 0; j < data->cols; j++)
			printf(" %d", data->matrix[i][j]);
		printf("\n");
	}
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
	print_matrix(data);
	return (1);
}

void	draw_line(t_mod *data)
{
	int x;
	int y;

	y = 200;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

void	draw_map(t_mod *data)
{
	mlx_expose_hook(data->win, draw_line, data);
	mlx_loop(data->mlx);
	sleep(10);
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
	draw_map(&data);
	close(fd);
}
