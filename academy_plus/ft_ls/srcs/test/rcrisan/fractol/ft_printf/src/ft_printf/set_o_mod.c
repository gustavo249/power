/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_o_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 11:24:17 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 14:01:35 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	assign_jo(va_list *ap, t_print *elements, t_flags flags)
{
	intmax_t	nbr;

	nbr = va_arg(*ap, intmax_t);
	elements->text = ft_ulltoa_base(nbr, 8, "01234567");
	return (get_width_precision(elements, flags));
}

static	int	assign_zo(va_list *ap, t_print *elements, t_flags flags)
{
	size_t	nbr;

	nbr = va_arg(*ap, size_t);
	elements->text = ft_ulltoa_base(nbr, 8, "01234567");
	return (get_width_precision(elements, flags));
}

int			set_o_mod(va_list *ap, t_flags flags)
{
	t_print elements;

	init_elements(&elements);
	if (flags.mod_ll)
		return (assign_llo(ap, &elements, flags));
	else if (flags.mod_l)
		return (assign_lo(ap, &elements, flags));
	else if (flags.mod_hh)
		return (assign_hho(ap, &elements, flags));
	else if (flags.mod_h)
		return (assign_ho(ap, &elements, flags));
	else if (flags.mod_j)
		return (assign_jo(ap, &elements, flags));
	else if (flags.mod_z)
		return (assign_zo(ap, &elements, flags));
	else
		return (assign_o(ap, &elements, flags));
}
