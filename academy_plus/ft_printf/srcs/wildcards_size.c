/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:27:05 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/22 15:28:03 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_wild_precision(va_list *arg)
{
	int		p_size;

	p_size = va_arg(*arg, int);
	return (p_size);
}

int		get_wild_width(va_list *arg)
{
	int w_size;

	w_size = va_arg(*arg, int);
	return (w_size);
}

char	*stock_damn_width(char *width, int len)
{
	int i;

	i = 0;
	while (len > 0)
	{
		width[i++] = ' ';
		len--;
	}
	width[i] = '\0';
	return (width);
}
