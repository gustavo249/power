/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_environment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 14:02:24 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/17 00:07:25 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_environment(t_env *e, char *type)
{
	e->mlx = mlx_init();
	if (ft_strequ(type, "J"))
		e->type = 'j';
	else if (ft_strequ(type, "H"))
		e->type = 'h';
	else if (ft_strequ(type, "M"))
		e->type = 'm';
	else if (ft_strequ(type, "D"))
		e->type = 'd';
	else if (ft_strequ(type, "K"))
		e->type = 'k';
	else
		print_error_and_exit();
	e->zoom = 250;
	e->color = 'w';
	e->step = 4;
	e->origin_x = WINDOW_WIDTH / 2;
	e->origin_y = WINDOW_HEIGHT / 2;
	e->win = mlx_new_window(e->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Fractol");
}
