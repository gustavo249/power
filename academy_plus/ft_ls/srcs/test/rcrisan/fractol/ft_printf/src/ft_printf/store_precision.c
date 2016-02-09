/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:40:59 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 09:49:37 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	store_precision(t_print *elements, t_flags flags)
{
	int	len;

	len = flags.precision - ft_strlen(elements->text);
	elements->precision =
		ft_memalloc(flags.precision - ft_strlen(elements->text) + 1);
	elements->precision = ft_memset(elements->precision, '0', len);
}
