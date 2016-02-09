/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 14:05:43 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/16 23:33:18 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_new_image(t_env *e)
{
	int		*bits;
	int		*size_line;
	int		endian;

	e->img = mlx_new_image(e->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	bits = malloc(sizeof(int));
	*bits = 32;
	size_line = malloc(sizeof(int));
	e->string = mlx_get_data_addr(e->img, bits, size_line, &endian);
}
