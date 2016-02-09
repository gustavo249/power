/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_jz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 10:12:06 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 10:42:13 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	assign_jd(va_list *ap, t_print *elements, t_flags flags)
{
	intmax_t	nbr;

	nbr = va_arg(*ap, intmax_t);
	elements->text = ft_lltoa_base(nbr, 10, "0123456789");
	return (get_width_precision(elements, flags));
}

int	assign_zd(va_list *ap, t_print *elements, t_flags flags)
{
	size_t	nbr;

	nbr = va_arg(*ap, size_t);
	elements->text = ft_lltoa_base(nbr, 10, "0123456789");
	return (get_width_precision(elements, flags));
}

int	assign_uj(va_list *ap, t_print *elements, t_flags flags)
{
	intmax_t	nbr;

	nbr = va_arg(*ap, intmax_t);
	elements->text = ft_ulltoa_base(nbr, 10, "0123456789");
	return (get_width_precision(elements, flags));
}

int	assign_uz(va_list *ap, t_print *elements, t_flags flags)
{
	size_t	nbr;

	nbr = va_arg(*ap, size_t);
	elements->text = ft_ulltoa_base(nbr, 10, "0123456789");
	return (get_width_precision(elements, flags));
}
