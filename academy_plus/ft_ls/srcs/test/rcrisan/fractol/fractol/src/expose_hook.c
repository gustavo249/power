/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 13:09:19 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/16 23:46:11 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *e)
{
	create_new_image(e);
	if (e->type == 'j')
		draw_julia(e);
	else if (e->type == 'h')
		draw_helga(e);
	else if (e->type == 'm')
		draw_mandelbrot(e);
	else if (e->type == 'k')
		draw_kosorus(e);
	else if (e->type == 'd')
		draw_druta(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	print_help(e);
	return (0);
}
