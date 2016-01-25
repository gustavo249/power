/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:24:57 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/25 17:39:28 by rcrisan          ###   ########.fr       */
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
}				t_env;

int		expose_hook(t_env *e);
void	draw(void *mlx, void *win);
int		key_hook(int keycode, t_env *e);
int		mouse_hook(int button,int x, int y, t_env *e);
void	init_struct(t_env *e);
void	read_matrix(void);
#endif
