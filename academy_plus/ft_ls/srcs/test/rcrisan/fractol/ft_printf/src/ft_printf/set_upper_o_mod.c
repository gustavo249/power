/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_upper_o_mod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:24:57 by azaha             #+#    #+#             */
/*   Updated: 2016/01/21 21:59:48 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_upper_o_mod(va_list *ap, t_flags flags)
{
	t_print elements;

	init_elements(&elements);
	return (assign_lo(ap, &elements, flags));
}
