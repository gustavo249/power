/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_d_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 09:25:42 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 10:44:05 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		assign_lld(va_list *ap, t_print *elem, t_flags flags)
{
	long long nbr;

	nbr = va_arg(*ap, long long);
	elem->text = ft_lltoa_base(nbr, 10, "0123456789");
	if (nbr < 0)
	{
		elem->minus = ft_strdup("-");
		elem->text = ft_strsub(elem->text, 1, ft_strlen(elem->text));
	}
	return (get_width_precision(elem, flags));
}

int		assign_ld(va_list *ap, t_print *elem, t_flags flags)
{
	long nbr;

	nbr = va_arg(*ap, long);
	elem->text = ft_lltoa_base(nbr, 10, "0123456789");
	if (nbr < 0)
	{
		elem->minus = ft_strdup("-");
		elem->text = ft_strsub(elem->text, 1, ft_strlen(elem->text));
	}
	return (get_width_precision(elem, flags));
}

int		assign_hhd(va_list *ap, t_print *elem, t_flags flags)
{
	char nbr;

	nbr = (char)va_arg(*ap, int);
	elem->text = ft_lltoa_base(nbr, 10, "0123456789");
	if (nbr < 0)
	{
		elem->minus = ft_strdup("-");
		elem->text = ft_strsub(elem->text, 1, ft_strlen(elem->text));
	}
	return (get_width_precision(elem, flags));
}

int		assign_hd(va_list *ap, t_print *elem, t_flags flags)
{
	short nbr;

	nbr = (short)va_arg(*ap, int);
	elem->text = ft_lltoa_base(nbr, 10, "0123456789");
	if (nbr < 0)
	{
		elem->minus = ft_strdup("-");
		elem->text = ft_strsub(elem->text, 1, ft_strlen(elem->text));
	}
	return (get_width_precision(elem, flags));
}

int		assign_d(va_list *ap, t_print *elem, t_flags flags)
{
	int nbr;

	nbr = va_arg(*ap, int);
	elem->text = ft_lltoa_base(nbr, 10, "0123456789");
	if (flags.space && !flags.plus && nbr >= 0)
		elem->space = ft_strdup(" ");
	if (nbr < 0)
	{
		elem->minus = ft_strdup("-");
		elem->text = ft_strsub(elem->text, 1, ft_strlen(elem->text));
	}
	if (nbr >= 0 && flags.plus == 1)
		elem->plus = ft_strdup("+");
	if (nbr == 0 && flags.dot)
		elem->text = ft_strdup("");
	return (get_width_precision(elem, flags));
}
