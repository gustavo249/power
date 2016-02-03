/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:24:57 by rcrisan           #+#    #+#             */
/*   Updated: 2016/02/03 16:13:06 by rcrisan          ###   ########.fr       */
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

typedef struct s_point
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

#endif
