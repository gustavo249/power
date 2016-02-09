/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 10:56:58 by azaha             #+#    #+#             */
/*   Updated: 2016/01/13 19:35:57 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_color(char color, unsigned char color_scale)
{
	unsigned char	*rgb;

	rgb = (unsigned char*)malloc(sizeof(unsigned char) * 4);
	if (color == 'r')
	{
		rgb[0] = color_scale;
		rgb[1] = color_scale;
		rgb[2] = 255;
	}
	if (color == 'b')
	{
		rgb[0] = 255;
		rgb[1] = color_scale;
		rgb[2] = color_scale;
	}
	if (color == 'y')
	{
		rgb[0] = color_scale;
		rgb[1] = 255;
		rgb[2] = 255;
	}
	return (*(int*)rgb);
}
