/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_u_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 21:30:01 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 10:43:53 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_u_mod(va_list *ap, t_flags flags)
{
	t_print elements;

	init_elements(&elements);
	if (flags.mod_ll)
		return (assign_ull(ap, &elements, flags));
	else if (flags.mod_l)
		return (assign_ul(ap, &elements, flags));
	else if (flags.mod_hh)
		return (assign_uhh(ap, &elements, flags));
	else if (flags.mod_h)
		return (assign_uh(ap, &elements, flags));
	else if (flags.mod_j)
		return (assign_uj(ap, &elements, flags));
	else if (flags.mod_z)
		return (assign_uz(ap, &elements, flags));
	else
		return (assign_u(ap, &elements, flags));
}
