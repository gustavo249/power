/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_x_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 09:20:01 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 14:02:58 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	assign_jx(va_list *ap, t_print *elements, t_flags flags)
{
	intmax_t	nbr;

	nbr = va_arg(*ap, intmax_t);
	elements->text = ft_ulltoa_base(nbr, 16, "0123456789abcdef");
	return (get_width_precision(elements, flags));
}

static	int	assign_zx(va_list *ap, t_print *elements, t_flags flags)
{
	size_t	nbr;

	nbr = va_arg(*ap, size_t);
	elements->text = ft_ulltoa_base(nbr, 16, "0123456789abcdef");
	return (get_width_precision(elements, flags));
}

int			set_x_mod(va_list *ap, t_flags flags)
{
	t_print elements;

	init_elements(&elements);
	if (flags.mod_ll)
		return (assign_llx(ap, &elements, flags));
	else if (flags.mod_l)
		return (assign_lx(ap, &elements, flags));
	else if (flags.mod_hh)
		return (assign_hhx(ap, &elements, flags));
	else if (flags.mod_h)
		return (assign_hx(ap, &elements, flags));
	else if (flags.mod_j)
		return (assign_jx(ap, &elements, flags));
	else if (flags.mod_z)
		return (assign_zx(ap, &elements, flags));
	else
		return (assign_x(ap, &elements, flags));
}
