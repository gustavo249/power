/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:15:35 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 13:06:44 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	try_nbr_specifiers(char *dsc, va_list *ap, t_flags flags)
{
	if (*dsc == 'd' || *dsc == 'i')
		return (set_d_mod(ap, flags));
	if (*dsc == 'x')
		return (set_x_mod(ap, flags));
	if (*dsc == 'o')
		return (set_o_mod(ap, flags));
	if (*dsc == 'u')
		return (set_u_mod(ap, flags));
	if (*dsc == 'p')
		return (assign_p(ap, flags));
	return (0);
}

static int	try_upper_case_specifiers(char *dsc, va_list *ap, t_flags flags)
{
	if (*dsc == 'D')
		return (set_upper_d_mod(ap, flags));
	if (*dsc == 'X')
		return (set_upper_x_mod(ap, flags));
	if (*dsc == 'O')
		return (set_upper_o_mod(ap, flags));
	if (*dsc == 'U')
		return (set_upper_u_mod(ap, flags));
	return (0);
}

static int	try_char_specifiers(char *dsc, va_list *ap, t_flags flags)
{
	if (*dsc == 'c' && flags.mod_l)
		return (assign_upper_c(ap, flags));
	else if (*dsc == 'c')
		return (assign_c(ap, flags));
	if (*dsc == 's' && flags.mod_l)
		return (assign_upper_s(ap, flags));
	else if (*dsc == 's')
		return (assign_s(ap, flags));
	if (*dsc == 'C')
		return (assign_upper_c(ap, flags));
	if (*dsc == 'S')
		return (assign_upper_s(ap, flags));
	return (0);
}

int			get_specifier(char *dsc, va_list *ap, t_flags flags)
{
	int	value;

	value = 0;
	value += try_nbr_specifiers(dsc, ap, flags);
	value += try_upper_case_specifiers(dsc, ap, flags);
	value += try_char_specifiers(dsc, ap, flags);
	return (value);
}
