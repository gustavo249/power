/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:17:09 by azaha             #+#    #+#             */
/*   Updated: 2016/01/13 18:32:01 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	print_legend(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, 20, WHITE, "Axonometry projection");
	mlx_string_put(e->mlx, e->win, 20, 40, WHITE, "Arrows : move");
	mlx_string_put(e->mlx, e->win, 20, 60, WHITE, "+/- : zoom in/out");
	mlx_string_put(e->mlx, e->win, 20, 80, WHITE,
			"Page Up/Down : increase/decrease height scale");
	mlx_string_put(e->mlx, e->win, 20, 100, WHITE,
			"SPACE : reset configuration");
	mlx_string_put(e->mlx, e->win, 20, 120, WHITE, "ESC : exit");
}

int				expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	draw(e);
	print_legend(e);
	return (0);
}
