/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:00:38 by rcrisan           #+#    #+#             */
/*   Updated: 2016/02/01 20:06:37 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//------------THE FUN BEGINS HERE--------
void	init_struct(t_mod *data)
{
	data->rows = 0;
	data->cols = 0;
	data->error = 0;
	data->times = 0;
}

//--------------ADDING THE NEW ROW FROM THE CHAR MATRIX--------

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

//----------------MOVING THE OLD CONTENT INTO A NEW MATRIX---------

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


//----OPTIONAL PRINTING--------

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

//-------------ADDING JUST THE FIRST ROW FOR COMPARISON-------------

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

//-----------------------READING MATRIX FROM FILE---------------

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

//----------------DRAWING FROM OLD POINTS TO NEW POINTS BASED ON HEIGHT-----------

/*
void	draw_between_points(t_mod *data)
{
	data->old_x = data->x;
	data->old_y = data->y;
	if (data->z > 0)
	{
		data->new_x = data->x / data->z;
		data->new_y = data->y / data->z;
	}
	else
	{
		data->new_x = data->x + data->line_size - 1;
		data->new_y = data->y + data->line_size + 1;
	}
	
}
*/

//------------FUNCTIA NUTS--------------

void	draw_line_axis(t_mod *data)
{
	float	t;
	float	step;
	float	x;
	float	y;

	step = 1 / (fmax(fabs(data->x1 - data->x), fabs(data->y1 - data->y)));
	t = 0;
	while (t < 1)
	{
		x = data->x + t * (data->x1 - data->x);
		y = data->y + t * (data->y1 - data->y);
		mlx_pixel_put(data->mlx, data->win, x, y, 0xFF0000);
		t = t + step;
	}
	data->x = data->x1;
	data->y = data->y1;
}

void	save_old_coords(t_mod *data)
{
	data->old_x = data->x;
	data->old_y = data->y;
}

void	get_new_coord(t_mod *data)
{
	save_old_coords(data);
	data->x1 = WIDTH / 2 + data->x * data->line_size * cos(30) - \
			   data->y * data->line_size - cos(30);
	data->y1 = HEIGHT / 2 + data->x * data->line_size * sin(30) + \
			   data->y * data->line_size * sin(30) - data->z * data->line_size;
	//draw_line_axis(data);
}


void	reset_x_coord(t_mod *data)
{
	/*if (data->times != 0)
	{
		data->x = data->x1;
		data->y = data->y1;
	}
	else*/
		data->x = data->old_x + data->line_size * data->times;
		data->y = data->old_y;
	data->times = 0;
}

void	reset_y_coord(t_mod *data)
{
	/*if (data->times != 0)
	{
		data->x = data->x1;
		data->y = data->y1;
	}
	else*/
		data->x = data->old_x;
		data->y = data->old_y + data->line_size * data->times;
	data->times = 0;
}

//-----------------DRAWING HORIZONTALLY-------------------

void draw_x_axis(t_mod *data)
{
	int i;
	int j;

	i = 0;
	data->y = 500 - data->rows / 2 * data->line_size;
	while (i < data->rows)
	{
		j = 0;
		data->x = 500 - data->cols / 2 * data->line_size; 
		while (j < data->cols - 1)
		{
			data->z = data->matrix[i][j];
			save_old_coords(data);
			if (data->z != 0)
			{
				data->times++;
				get_new_coord(data);	
				/*data->x = data->x1 + data->line_size;
				data->y = data->y1;*/
			}
			else
			{
				data->times = 0;	
				data->x1 = data->x + data->line_size;
				data->y1 = data->y;
			}
			draw_line_axis(data);
			if (data->z != 0)
				reset_x_coord(data);
			j++;
		}
		data->y = data->y + data->line_size;
		i++;
	}
}

//--------------------DRAWING VERTICALLY ---------------

void	draw_y_axis(t_mod *data)
{
	int i;
	int j;

	i = 0;
	data->x = 500 - data->cols / 2 * data->line_size; 
	while (i < data->cols)
	{
		j = 0;
		data->y = 500 - data->rows / 2 * data->line_size;
		while (j < data->rows - 1)
		{
			data->z = data->matrix[j][i];
			save_old_coords(data);
			if (data->z != 0)
			{
				data->times++;
				get_new_coord(data);
				/*data->x = data->x1;
				data->y = data->y1 + data->line_size;*/
			}
			else
			{
				data->times = 0;
				data->y1 = data->y + data->line_size;
				data->x1 = data->x;
			}
			draw_line_axis(data);
			if (data->z != 0)
				reset_y_coord(data);
			j++;
		}
		data->x = data->x + data->line_size;
		i++;
	}
}

void	draw(t_mod *data)
{
	draw_x_axis(data);
	draw_y_axis(data);
}

//-----------EXIT WHEN ESC KEY IS PRESSED-------------

int key_hook(int keycode, t_mod *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

//-----------HOW MANY PIXELS OUT LINE SHOUD HAVE ? -----------

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

//------------EXPOSE HOOK CALLED FUNCTION-----------

int		draw_matrix(t_mod *data)
{
	get_size(data);
	draw(data);
	return (0);
}

//---------------DRAWING CORE---------------

void	draw_map(t_mod *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 1000, "win");
	mlx_key_hook(data->win, key_hook, data);
	mlx_expose_hook(data->win, draw_matrix, data);
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
