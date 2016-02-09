/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_c_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:47:51 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 13:57:48 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	assign_c(va_list *ap, t_flags flags)
{
	char	chr;
	char	*spaces;

	chr = va_arg(*ap, int);
	if (flags.width > 1)
	{
		spaces = ft_strnew(flags.width - 1);
		if (flags.zero)
			spaces = ft_memset(spaces, '0', flags.width - 1);
		else
			spaces = ft_memset(spaces, ' ', flags.width - 1);
		if (flags.minus == 1)
		{
			ft_putchar(chr);
			ft_putstr(spaces);
		}
		else
		{
			ft_putstr(spaces);
			ft_putchar(chr);
		}
		return (flags.width);
	}
	ft_putchar(chr);
	return (1);
}
