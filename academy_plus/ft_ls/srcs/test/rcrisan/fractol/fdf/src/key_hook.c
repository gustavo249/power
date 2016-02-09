/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:05:10 by azaha             #+#    #+#             */
/*   Updated: 2016/01/13 19:52:12 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	get_color_key(int keycode, t_env *e)
{
	if (keycode == 15)
		e->map_config->color = 'r';
	if (keycode == 11)
		e->map_config->color = 'b';
	if (keycode == 16)
		e->map_config->color = 'y';
}

static	void	get_offset_key(int keycode, t_env *e)
{
	if (keycode == 124)
		e->map_config->x_offset += OFFSET;
	if (keycode == 123)
		e->map_config->x_offset -= OFFSET;
	if (keycode == 125)
		e->map_config->y_offset += OFFSET;
	if (keycode == 126)
		e->map_config->y_offset -= OFFSET;
}

static	void	get_zoom_key(int keycode, t_env *e)
{
	if (keycode == 69)
		e->map_config->zoom += ZOOM;
	if (keycode == 78)
		e->map_config->zoom -= ZOOM;
}

static	void	get_hs_key(int keycode, t_env *e)
{
	if (keycode == 116)
		e->map_config->height_scale += 0.33;
	if (keycode == 121)
		e->map_config->height_scale -= 0.33;
}

int				key_hook(int keycode, t_env *e)
{
	get_hs_key(keycode, e);
	get_zoom_key(keycode, e);
	get_color_key(keycode, e);
	get_offset_key(keycode, e);
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		reset_configuration(e);
	calculate_axonometry_coords(e);
	expose_hook(e);
	return (0);
}
