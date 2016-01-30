/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:24:57 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/30 19:08:47 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
# include "libft.h"

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			rows;
	int			cols;
	int			**matrix;
	int			error;
	char		**content;
	int			line_size;
	float		old_x;
	float		old_y;
	float		x;
	float		y;
	float		z;
}				t_mod;

#endif
