/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:35:36 by azaha             #+#    #+#             */
/*   Updated: 2016/01/21 14:08:42 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	store_x_hash(t_print *elements, t_flags flags)
{
	if (flags.hash == 1)
		elements->sign = ft_strdup("0x");
}

void	store_upper_x_hash(t_print *elements, t_flags flags)
{
	if (flags.hash == 1)
		elements->sign = ft_strdup("0X");
}

void	store_o_hash(t_print *elements, t_flags flags)
{
	if (flags.hash == 1)
		elements->sign = ft_strdup("0");
}
