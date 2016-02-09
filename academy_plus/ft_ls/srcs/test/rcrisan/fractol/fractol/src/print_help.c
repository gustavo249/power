/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 23:46:21 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/17 00:09:55 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_title(t_env *e)
{
	if (e->type == 'm')
		mlx_string_put(e->mlx, e->win, 20, 20, 0xffffff, "Mandelbrot");
	if (e->type == 'j')
		mlx_string_put(e->mlx, e->win, 20, 20, 0xffffff, "Julia");
	if (e->type == 'd')
		mlx_string_put(e->mlx, e->win, 20, 20, 0xffffff, "Druta");
	if (e->type == 'k')
		mlx_string_put(e->mlx, e->win, 20, 20, 0xffffff, "Kosorus");
	if (e->type == 'h')
		mlx_string_put(e->mlx, e->win, 20, 20, 0xffffff, "Helga");
}

void		print_help(t_env *e)
{
	print_title(e);
	if (e->type == 'j' || e->type == 'h')
		mlx_string_put(e->mlx, e->win, 20, 40, 0xffffff,
				"mouse motion: modify");
	else
		mlx_string_put(e->mlx, e->win, 20, 40, 0xffffff,
				"mouse wheel: zoom");
	mlx_string_put(e->mlx, e->win, 20, 60, 0xffffff,
			"+/-: change complexity");
	mlx_string_put(e->mlx, e->win, 20, 80, 0xffffff,
			"w/r/g/b: change color");
	mlx_string_put(e->mlx, e->win, 20, 60, 0xffffff,
			"+/-: change complexity");
	if (e->type != 'j' && e->type != 'h')
		mlx_string_put(e->mlx, e->win, 20, 100, 0xffffff,
				"arrows: move");
}
