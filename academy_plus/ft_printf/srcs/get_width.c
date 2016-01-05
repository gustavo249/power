/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:09:22 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/05 15:22:04 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_width(char *format)
{
	int i;
	char *width;
	int w;
	int j;

	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			j = i;
			while (ft_isdigit(format[i]) == 1)
				i++;
			width = ft_strsub(format, j, i - j);
		}
		i++;
	}
	w = atoi(width);
	return (w);
}
