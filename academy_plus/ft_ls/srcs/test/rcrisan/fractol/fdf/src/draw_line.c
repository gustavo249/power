/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 22:54:58 by azaha             #+#    #+#             */
/*   Updated: 2016/01/13 19:22:48 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	float	ft_abs(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static	float	get_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void			draw_line(t_env *e, t_point a, t_point b)
{
	int		color;
	float	index;
	float	fractions;

	index = 0;
	fractions = get_max(ft_abs(a.w_x - b.w_x), ft_abs(a.w_y - b.w_y));
	while (index <= fractions)
	{
		color = get_color(e->map_config->color, a.color_scale +
				(b.color_scale - a.color_scale) * index / fractions);
		mlx_pixel_put(e->mlx, e->win,
				a.w_x + index / fractions * (b.w_x - a.w_x),
				a.w_y + index / fractions * (b.w_y - a.w_y), color);
		index += 1;
	}
}
