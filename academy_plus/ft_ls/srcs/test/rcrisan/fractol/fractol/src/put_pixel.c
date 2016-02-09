/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 12:33:41 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/16 22:17:06 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(char *string, char color, char rgb)
{
	if (rgb == 'w')
	{
		string[0] = color;
		string[1] = color;
		string[2] = color;
	}
	else if (rgb == 'r')
		string[2] = color;
	else if (rgb == 'g')
		string[1] = color;
	else if (rgb == 'b')
		string[0] = color;
}
