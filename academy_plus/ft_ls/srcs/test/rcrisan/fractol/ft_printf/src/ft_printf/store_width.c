/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:36:36 by azaha             #+#    #+#             */
/*   Updated: 2016/01/21 23:02:14 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	store_width(t_print *elements, t_flags flags)
{
	int	len;

	len = flags.width - ft_strlen(elements->precision) -
		ft_strlen(elements->text) - ft_strlen(elements->plus);
	if (flags.hash == 1)
		len -= 2;
	if (flags.space && !flags.plus)
		len -= 1;
	if (ft_strequ(elements->minus, "-"))
		len -= 1;
	if (len > 0)
	{
		elements->width = ft_strnew(len + 1);
		if (flags.zero && flags.dot != 1 && flags.minus != 1)
			elements->width = ft_memset(elements->width, '0', len);
		else
			elements->width = ft_memset(elements->width, ' ', len);
	}
}
