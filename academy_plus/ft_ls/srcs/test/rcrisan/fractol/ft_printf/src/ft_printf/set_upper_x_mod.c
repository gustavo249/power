/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_upper_x_mod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 10:44:40 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 14:02:40 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	assign_upper_jx(va_list *ap, t_print *elements, t_flags flags)
{
	intmax_t	nbr;

	nbr = va_arg(*ap, intmax_t);
	elements->text = ft_ulltoa_base(nbr, 16, "0123456789ABCDEF");
	return (get_width_precision(elements, flags));
}

static	int	assign_upper_zx(va_list *ap, t_print *elements, t_flags flags)
{
	size_t	nbr;

	nbr = va_arg(*ap, size_t);
	elements->text = ft_ulltoa_base(nbr, 16, "0123456789ABCDEF");
	return (get_width_precision(elements, flags));
}

int			set_upper_x_mod(va_list *ap, t_flags flags)
{
	t_print elements;

	init_elements(&elements);
	if (flags.mod_ll)
		return (assign_upper_llx(ap, &elements, flags));
	else if (flags.mod_l)
		return (assign_upper_lx(ap, &elements, flags));
	else if (flags.mod_hh)
		return (assign_upper_hhx(ap, &elements, flags));
	else if (flags.mod_h)
		return (assign_upper_hx(ap, &elements, flags));
	else if (flags.mod_j)
		return (assign_upper_jx(ap, &elements, flags));
	else if (flags.mod_z)
		return (assign_upper_zx(ap, &elements, flags));
	else
		return (assign_upper_x(ap, &elements, flags));
}
