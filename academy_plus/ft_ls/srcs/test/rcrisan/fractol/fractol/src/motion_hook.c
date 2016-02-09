/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mation_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 20:54:57 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/16 23:25:55 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		motion_hook(int x, int y, t_env *e)
{
	e->move_x = (x - e->origin_x) / 250;
	e->move_y = (y - e->origin_y) / 250;
	expose_hook(e);
	return (0);
}
