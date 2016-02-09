/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_correct_dsc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 10:56:29 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 09:13:07 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			process_correct_dsc(char *dsc, va_list *ap)
{
	int		value;
	t_flags	flags;

	value = 0;
	init_flags(&flags);
	while (*dsc)
	{
		check_flags(&dsc, &flags);
		check_mods(&dsc, &flags);
		if (*dsc != '0')
			check_numbers(&dsc, &flags);
		value = get_specifier(dsc, ap, flags);
		dsc++;
	}
	return (value);
}
