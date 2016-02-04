/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:00:53 by rcrisan           #+#    #+#             */
/*   Updated: 2016/02/03 17:09:22 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**get_initial_coords(t_mod *data)
{
	t_point		**temp;
	int			i;
	int			j;

	i = 0;
	temp = (t_point**)malloc(sizeof(t_point*) * data->rows);
	while (i < data->rows)
	{
		temp[i] = (t_point*)malloc(sizeof(t_point) * data->cols);
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

t_point		**get_isometric_coords(t_mod *data)
{
	t_point		**matrix;
	int			i;
	int			j;

	i = 0;
	matrix = (t_point**)malloc(sizeof(t_point*) * data->rows);
	while (i < data->rows)
	{
		j = 0;
		matrix[i] = (t_point*)malloc(sizeof(t_point) * data->cols);
		while (j < data->cols)
		{
			matrix[i][j].x = WIDTH / 2 + data->m2[i][j].x * data->line_size * \
								cos(DEG30) - data->m2[i][j].y * \
								data->line_size * cos(DEG30);
			matrix[i][j].y = HEIGHT / 2 + data->m2[i][j].x * data->line_size * \
							sin(DEG30) + data->m2[i][j].y * data->line_size * \
							sin(DEG30) - data->m2[i][j].z * data->line_size;
			matrix[i][j].z = data->m2[i][j].z;
			j++;
		}
		i++;
	}
	return (matrix);
}

void		transform_all_points_relative_to_map_center(t_mod *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->cols)
		{
			m->m2[i][j].x -= (m->cols / 2);
			m->m2[i][j].y -= (m->rows / 2);
			j++;
		}
		i++;
	}
}

void		control_height(t_mod *data)
{
	int		i;
	int		j;
	float	k;

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

void		modify_z(t_mod *data, int control)
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
