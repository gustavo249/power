/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:24:57 by rcrisan           #+#    #+#             */
/*   Updated: 2016/02/03 17:30:17 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include <math.h>
# define WIDTH 1000
# define HEIGHT 1000
# define DEG30 0.52398776

typedef struct	s_point
{
	float	x;
	float	y;
	float	z;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			rows;
	int			cols;
	int			**matrix;
	t_point		**m2;
	int			error;
	char		**content;
	float		line_size;
	float		min_z;
	float		max_z;
	int			white;
}				t_mod;

void			init_struct(t_mod *data);
int				**add_new_content(int **new_matrix, t_mod *data, int *i);
int				**add_new_row(t_mod *data);
int				**add_first_row(t_mod *data, int fd);
int				read_matrix(int fd, t_mod *data);
void			get_min_max_height(t_mod *data);
int				get_color(t_mod *data);
void			draw_line_axis(t_mod *data, t_point v, t_point v1);
void			draw_between_points(t_mod *data, t_point **matrix);
t_point			**get_initial_coords(t_mod *data);
t_point			**get_isometric_coords(t_mod *data);
void			transform_all_points_relative_to_map_center(t_mod *m);
void			control_height(t_mod *data);
void			modify_z(t_mod *data, int control);
void			draw(t_mod *data);
int				key_hook(int keycode, t_mod *data);
void			get_size(t_mod *data);
int				draw_matrix(t_mod *data);
void			draw_map(t_mod *data);
void			show_usage(t_mod *data);

#endif
