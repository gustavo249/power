/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_configuration.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 09:35:42 by azaha             #+#    #+#             */
/*   Updated: 2016/01/13 19:05:45 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	reset_configuration(t_env *e)
{
	e->map_config->zoom = 1;
	e->map_config->color = 'r';
	e->map_config->x_offset = 0;
	e->map_config->y_offset = 0;
	e->map_config->height_scale = 1;
	calculate_axonometry_coords(e);
}
