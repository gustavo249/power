/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_incorrect_dsc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:53:03 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 09:13:07 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	compute_wrong_dsc(char *dsc, t_flags flags)
{
	int		len;
	char	space;

	len = 1;
	space = ' ';
	if (flags.zero)
		space = '0';
	if (!flags.minus)
		while (flags.width > 1)
		{
			ft_putchar(space);
			len++;
			flags.width--;
		}
	ft_putchar(*dsc);
	while (flags.width > 1)
	{
		ft_putchar(space);
		len++;
		flags.width--;
	}
	return (len);
}

int			process_incorrect_dsc(char *dsc, va_list *ap)
{
	int		value;
	t_flags	flags;

	init_flags(&flags);
	(void)ap;
	while (*dsc)
	{
		check_flags(&dsc, &flags);
		check_mods(&dsc, &flags);
		if (*dsc != '0')
			check_numbers(&dsc, &flags);
		if (wrong_specifier(*dsc) && *(dsc + 1) == '\0')
			value = compute_wrong_dsc(dsc, flags);
		dsc++;
	}
	return (value);
}
