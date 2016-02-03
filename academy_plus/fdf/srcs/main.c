/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:00:38 by rcrisan           #+#    #+#             */
/*   Updated: 2016/02/03 14:28:43 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//------------THE FUN BEGINS HERE--------
void	init_struct(t_mod *data)
{
	data->rows = 0;
	data->cols = 0;
	data->error = 0;
	data->min_z = 0;
	data->max_z = 0;
	data->white = 0x00FF00;
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
	return (1);
}



//------------MIN HEIGHT AND MAX HEIGHT---------------


void	get_min_max_height(t_mod *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->m2[i][j].z > data->max_z)
				data->max_z = data->m2[i][j].z;
			if (data->m2[i][j].z < data->min_z)
				data->min_z = data->m2[i][j].z;
			j++;
		}
		i++;
	}
}

//--------------GET COLOR------------------------------

int		get_color(t_mod *data)
{
	int red;
	int v;
	int white;
	float height_size;

	white = 0xFFFFFF;
	red = 0xFF0000;
	height_size = data->max_z - data->min_z;
	v = height_size / HEIGHT * 255;
	data->white -= v - 5;
	return (data->white);
}

//------------BASIC FUNCTION WHICH DRAWS A SINGLE LINE FROM X Y TO X1 AND Y1-----------

void	draw_line_axis(t_mod *data, t_point v, t_point v1)
{
	float	t;
	float	step;
	float	x;
	float	y;

	step = 1 / (fmax(fabs(v1.x - v.x), fabs(v1.y - v.y)));
	t = 0;
	while (t < 1)
	{
		x = v.x + t * (v1.x - v.x);
		y = v.y + t * (v1.y - v.y);
		mlx_pixel_put(data->mlx, data->win, x, y, get_color(data));
		t = t + step;
	}
}

//-------------------DRAW A LINE BETWEEN EACH POINT IN THE MATRIX--------------

void	draw_between_points(t_mod *data, t_point **matrix)
{
	int i;
	int j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (j < data->cols - 1)
				draw_line_axis(data, matrix[i][j], matrix[i][j + 1]);
			if (i < data->rows - 1)
				draw_line_axis(data, matrix[i][j], matrix[i + 1][j]);
			j++;
		}
		i++;
	}
}

//----------------------GETTING X AND Y COORDS BASED ON ROWS AND COLUMNS----------------

t_point		**get_initial_coords(t_mod *data)
{
	t_point		**temp;
	int			i;
	int			j;

	i = 0;
	temp = (t_point**)malloc(sizeof(t_point*) * data->rows);
	while (i < data->rows)
	{
		temp[i]= (t_point*)malloc(sizeof(t_point) * data->cols);
		j = 0;
		while (j < data->cols)
		{
			temp[i][j].x = j;
			temp[i][j].y = i;
			temp[i][j].z = data->matrix[i][j];
			j++;
		}
		i++;
	}
	return (temp);
}

//---------------------CREATING A MATRIX STRUCTURE WHICH CONTAINS X Y AND Z COORDS BASED ON HIGHT--------

t_point		**get_isometric_coords(t_mod *data)
{
	t_point		**matrix;
	int 		i;
	int			j;

	i = 0;
	matrix = (t_point**)malloc(sizeof(t_point*) * data->rows);
	while (i < data->rows)
	{
		j = 0;
		matrix[i] = (t_point*)malloc(sizeof(t_point) * data->cols);
		while (j < data->cols)
		{
			matrix[i][j].x = WIDTH / 2 + data->m2[i][j].x * data->line_size * cos(DEG30) - \
							 data->m2[i][j].y * data->line_size * cos(DEG30);
			matrix[i][j].y = HEIGHT / 2 + data->m2[i][j].x * data->line_size * sin(DEG30) + \
							 data->m2[i][j].y * data->line_size * sin(DEG30) - \
							 data->m2[i][j].z * data->line_size;
			matrix[i][j].z = data->m2[i][j].z;
			j++;
		}
		i++;
	}
	return (matrix);
}

//------------------CENTRE THE COORDINATES IN THE MIDDLE--------------

void	transform_all_points_relative_to_map_center(t_mod *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->cols)
		{
			(m->m2)[i][j].x -= (m->cols / 2);
			(m->m2)[i][j].y -= (m->rows / 2);
			j++;
		}
		i++;
	}
}

void	control_height(t_mod *data)
{
	int i;
	int j;
	float k;

	i = 0;
	k = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->m2[i][j].z < 0)
				k = data->m2[i][j].z * -1;
			else
				k = data->m2[i][j].z;
			if (k >= 40)
				data->m2[i][j].z /= 10;
			else if (k >= 20)
				data->m2[i][j].z /= 6;
			else
				data->m2[i][j].z /= 4;
			j++;
		}
		i++;
	}
}

void	modify_z(t_mod *data, int control)
{
	int i;
	int j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (control == 1)
				data->m2[i][j].z *= 2;
			else if (control == -1)
				data->m2[i][j].z /= 2;
			j++;
		}
		i++;
	}
}

//--------------DRAWING CORE------------------

void	draw(t_mod *data)
{
	t_point **matrix;

	data->m2 = get_initial_coords(data);
	get_min_max_height(data);
	transform_all_points_relative_to_map_center(data);
	control_height(data);
	matrix = get_isometric_coords(data);
	draw_between_points(data, matrix);

}

//-----------EXIT WHEN ESC KEY IS PRESSED-------------

int	draw_matrix(t_mod *data);

int key_hook(int keycode, t_mod *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (keycode == 126)
	{
		modify_z(data, 1);
		draw_matrix(data);
	}
	else if (keycode == 125)
	{
		modify_z(data, -1);
		draw_matrix(data);
	}
	return (0);
}

//-----------HOW MANY PIXELS OUT LINE SHOUD HAVE ? -----------

void	get_size(t_mod *data)
{
	if (data->cols > 100)
		data->line_size = (WIDTH - 300) / data->cols;
	else
		data->line_size = (WIDTH - 600) / data->cols;

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
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "win");	
	mlx_expose_hook(data->win, draw_matrix, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
	sleep(10);
}

int main (int argc, char **argv)
{
	t_mod	data;
	int		fd;

	if (argc != 2)
	{
		ft_putstr("No input file or too many\n");
		return (-1);
	}
	fd = open (argv[1], O_RDONLY);
	init_struct(&data);
	read_matrix(fd, &data);
	draw_map(&data);	
	close(fd);
	return (0);
}
