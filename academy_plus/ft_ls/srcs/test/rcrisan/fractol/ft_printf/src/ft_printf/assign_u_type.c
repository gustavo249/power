/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_u_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 21:52:49 by azaha             #+#    #+#             */
/*   Updated: 2016/01/21 21:56:00 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		assign_ull(va_list *ap, t_print *elem, t_flags flags)
{
	unsigned long long nbr;

	nbr = va_arg(*ap, unsigned long long);
	if (nbr == 0 && flags.dot == 1)
		elem->text = ft_strdup("");
	else
		elem->text = ft_ulltoa_base(nbr, 10, "0123456789");
	if (nbr != 0)
		store_x_hash(elem, flags);
	return (get_width_precision(elem, flags));
}

int		assign_ul(va_list *ap, t_print *elem, t_flags flags)
{
	unsigned long nbr;

	nbr = va_arg(*ap, unsigned long);
	if (nbr == 0 && flags.dot == 1)
		elem->text = ft_strdup("");
	else
		elem->text = ft_ulltoa_base(nbr, 10, "0123456789");
	if (nbr != 0)
		store_x_hash(elem, flags);
	return (get_width_precision(elem, flags));
}

int		assign_uhh(va_list *ap, t_print *elem, t_flags flags)
{
	unsigned char nbr;

	nbr = (char)va_arg(*ap, unsigned int);
	if (nbr == 0 && flags.dot == 1)
		elem->text = ft_strdup("");
	else
		elem->text = ft_ulltoa_base(nbr, 10, "0123456789");
	if (nbr != 0)
		store_x_hash(elem, flags);
	return (get_width_precision(elem, flags));
}

int		assign_uh(va_list *ap, t_print *elem, t_flags flags)
{
	unsigned short nbr;

	nbr = (short)va_arg(*ap, unsigned int);
	if (nbr == 0 && flags.dot == 1)
		elem->text = ft_strdup("");
	else
		elem->text = ft_ulltoa_base(nbr, 10, "0123456789");
	if (nbr != 0)
		store_x_hash(elem, flags);
	return (get_width_precision(elem, flags));
}

int		assign_u(va_list *ap, t_print *elem, t_flags flags)
{
	unsigned int nbr;

	nbr = va_arg(*ap, unsigned int);
	if (nbr == 0 && flags.dot == 1)
		elem->text = ft_strdup("");
	else
		elem->text = ft_ulltoa_base(nbr, 10, "0123456789");
	if (nbr != 0)
		store_x_hash(elem, flags);
	return (get_width_precision(elem, flags));
}
