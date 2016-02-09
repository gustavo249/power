/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 14:20:59 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/16 23:25:38 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	movement_key_hook(int keycode, t_env *e)
{
	if (keycode == 126)
	{
		e->origin_y += 200;
		expose_hook(e);
	}
	if (keycode == 125)
	{
		e->origin_y -= 200;
		expose_hook(e);
	}
	if (keycode == 123)
	{
		e->origin_x += 200;
		expose_hook(e);
	}
	if (keycode == 124)
	{
		e->origin_x -= 200;
		expose_hook(e);
	}
}

static void	color_key_hook(int keycode, t_env *e)
{
	if (keycode == 13)
	{
		e->color = 'w';
		expose_hook(e);
	}
	if (keycode == 5)
	{
		e->color = 'g';
		expose_hook(e);
	}
	if (keycode == 11)
	{
		e->color = 'b';
		expose_hook(e);
	}
	if (keycode == 15)
	{
		e->color = 'r';
		expose_hook(e);
	}
}

static void	modify_step(int keycode, t_env *e)
{
	if (keycode == 78)
	{
		if (e->step < 10)
			(e->step)++;
		expose_hook(e);
	}
	if (keycode == 69)
	{
		if (e->step > 1)
			(e->step)--;
		expose_hook(e);
	}
}

int			key_hook(int keycode, t_env *e)
{
	movement_key_hook(keycode, e);
	color_key_hook(keycode, e);
	modify_step(keycode, e);
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
	{
		e->origin_y = WINDOW_HEIGHT / 2;
		e->origin_x = WINDOW_WIDTH / 2;
		e->zoom = 250;
		expose_hook(e);
	}
	return (0);
}
