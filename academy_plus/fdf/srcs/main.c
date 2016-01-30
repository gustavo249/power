/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:00:38 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/30 19:08:45 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_struct(t_mod *data)
{
	data->rows = 0;
	data->cols = 0;
	data->error = 0;
	data->x = 100;
	data->y = 500;
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

	printf("ROWS = %d\tCOLS =%d\n", data->rows, data->cols);
	return (1);
}

void	get_coord(t_mod *data)
{
	data->x = data->x / data->z;
	data->y = data->y / data->z;
}

void	get_z(t_mod *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			data->z = data->matrix[i][j];
			if (data->z > 0)
				get_coord(data);
			j++;
		}
		i++;
	}
}

void	draw_between_points(t_mod *data)
{
	float x;
	float y;
	float x1;
	float y1;
	int k;

	printf("X = %f\tY = %f\n", data->x, data->y);
	x = data->x;
	y = data->y;
	k = data->line_size;
	get_z(data);
	x1 = data->x;
	y1= data->y;

	

}

void	reset_coord(t_mod *data)
{
	data->x = 100 + data->line_size;
	data->y = 500 + data->line_size;
}

void draw_x_axis(t_mod *data)
{
	int i;
	int j;
	int k;

	i = 0;
	data->y = 500;
	while (i < data->rows)
	{
		j = 0;
		data->x = 100;
		while (j < data->cols - 1)
		{
			k = data->line_size;
			draw_between_points(data);
			/*while (k >= 0)	
			{
				mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0xFF0000);
				k--;
				data->x++;
			}*/
			j++;
		}
		data->y = data->y + data->line_size;
		i++;
	}
}

void	draw_y_axis(t_mod *data)
{
	int i;
	int j;
	int k;

	i = 0;
	data->x = 100;
	while (i < data->cols)
	{
		j = 0;
		data->y = 500;
		while (j < data->rows - 1)
		{
			k = data->line_size;
			while (k >= 0)
			{
				mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0xFF0000);
				k--;
				data->y++;
			}
			j++;
		}
		data->x += data->line_size;
		i++;
	}
}

void	draw(t_mod *data)
{
	draw_x_axis(data);
	draw_y_axis(data);
}

int key_hook(int keycode, t_mod *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

void	get_size(t_mod *data)
{
	if (data->rows < 10 || data->cols < 10)
		data->line_size = 20;
	else if (data->rows < 30 || data->cols < 30)
		data->line_size = 15;
	else if (data->rows < 50 || data->cols < 50)
		data->line_size = 10;
	else if (data->rows < 100 || data->cols < 100)
		data->line_size = 8;
	else if (data->rows > 100 || data->cols > 100)
		data->line_size = 3;
}

int		draw_line(t_mod *data)
{
	get_size(data);
	draw(data);
	return (0);
}

void	draw_map(t_mod *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 1000, "win");
	mlx_key_hook(data->win, key_hook, data);
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
	return (0);
}
