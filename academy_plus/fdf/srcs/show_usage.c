/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:13:01 by rcrisan           #+#    #+#             */
/*   Updated: 2016/02/03 17:13:45 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show_usage(t_mod *data)
{
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFF0000, "Usage:");
	mlx_string_put(data->mlx, data->win, 70, 10, 0xFF0000, \
			"move the up and down arrows to change the color");
	mlx_string_put(data->mlx, data->win, 10, 40, 0xFF0000, \
			"Press ESC to close the program");
}
