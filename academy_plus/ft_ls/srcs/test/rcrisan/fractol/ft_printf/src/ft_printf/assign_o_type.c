/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_o_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 11:25:13 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 10:45:26 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		assign_llo(va_list *ap, t_print *elem, t_flags flags)
{
	unsigned long long nbr;

	nbr = va_arg(*ap, unsigned long long);
	if (nbr == 0 && flags.dot == 1)
		elem->text = ft_strdup("");
	else
		elem->text = ft_ulltoa_base(nbr, 8, "01234567");
	if (nbr != 0)
		store_o_hash(elem, flags);
	if (flags.dot && flags.hash)
		elem->sign = ft_strdup("0");
	return (get_width_precision(elem, flags));
}

int		assign_lo(va_list *ap, t_print *elem, t_flags flags)
{
	unsigned long nbr;

	nbr = va_arg(*ap, unsigned long);
	if (nbr == 0 && flags.dot == 1)
		elem->text = ft_strdup("");
	else
		elem->text = ft_ulltoa_base(nbr, 8, "01234567");
	if (nbr != 0)
		store_o_hash(elem, flags);
	if (flags.dot && flags.hash)
		elem->sign = ft_strdup("0");
	return (get_width_precision(elem, flags));
}

int		assign_hho(va_list *ap, t_print *elem, t_flags flags)
{
	unsigned char nbr;

	nbr = (char)va_arg(*ap, unsigned int);
	if (nbr == 0 && flags.dot == 1)
		elem->text = ft_strdup("");
	else
		elem->text = ft_ulltoa_base(nbr, 8, "01234567");
	if (nbr != 0)
		store_o_hash(elem, flags);
	if (flags.dot && flags.hash)
		elem->sign = ft_strdup("0");
	return (get_width_precision(elem, flags));
}

int		assign_ho(va_list *ap, t_print *elem, t_flags flags)
{
	unsigned short nbr;

	nbr = (short)va_arg(*ap, unsigned int);
	if (nbr == 0 && flags.dot == 1)
		elem->text = ft_strdup("");
	else
		elem->text = ft_ulltoa_base(nbr, 8, "01234567");
	if (nbr != 0)
		store_o_hash(elem, flags);
	if (flags.dot && flags.hash)
		elem->sign = ft_strdup("0");
	return (get_width_precision(elem, flags));
}

int		assign_o(va_list *ap, t_print *elem, t_flags flags)
{
	unsigned int nbr;

	nbr = va_arg(*ap, unsigned int);
	if (nbr == 0 && flags.dot == 1)
		elem->text = ft_strdup("");
	else
		elem->text = ft_ulltoa_base(nbr, 8, "01234567");
	if (nbr != 0)
		store_o_hash(elem, flags);
	if (flags.dot && flags.hash)
		elem->sign = ft_strdup("0");
	if (flags.dot && flags.hash && flags.precision)
		elem->sign = ft_strdup("");
	return (get_width_precision(elem, flags));
}
