/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_upper_d_mod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 20:56:54 by azaha             #+#    #+#             */
/*   Updated: 2016/01/21 09:45:11 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_upper_d_mod(va_list *ap, t_flags flags)
{
	t_print elements;

	init_elements(&elements);
	return (assign_ld(ap, &elements, flags));
}
