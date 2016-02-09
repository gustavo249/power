/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_upper_u_mod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 21:56:57 by azaha             #+#    #+#             */
/*   Updated: 2016/01/21 21:59:46 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_upper_u_mod(va_list *ap, t_flags flags)
{
	t_print elements;

	init_elements(&elements);
	return (assign_ul(ap, &elements, flags));
}
