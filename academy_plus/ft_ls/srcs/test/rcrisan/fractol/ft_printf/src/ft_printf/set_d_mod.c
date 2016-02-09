/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_d_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 14:17:15 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 10:44:06 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	set_d_mod(va_list *ap, t_flags flags)
{
	t_print elements;

	init_elements(&elements);
	if (flags.mod_ll)
		return (assign_lld(ap, &elements, flags));
	else if (flags.mod_l)
		return (assign_ld(ap, &elements, flags));
	else if (flags.mod_hh)
		return (assign_hhd(ap, &elements, flags));
	else if (flags.mod_h)
		return (assign_hd(ap, &elements, flags));
	else if (flags.mod_j)
		return (assign_jd(ap, &elements, flags));
	else if (flags.mod_z)
		return (assign_zd(ap, &elements, flags));
	else
		return (assign_d(ap, &elements, flags));
}
