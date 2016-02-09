/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:05:08 by azaha             #+#    #+#             */
/*   Updated: 2016/01/20 10:12:44 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_mods(char **dsc, t_flags *flags)
{
	if (**dsc == 'h' && *(*dsc + 1) == 'h')
	{
		flags->mod_hh = 1;
		(*dsc)++;
	}
	else if (**dsc == 'l' && *(*dsc + 1) == 'l')
	{
		flags->mod_ll = 1;
		(*dsc)++;
	}
	else if (**dsc == 'h')
		flags->mod_h = 1;
	else if (**dsc == 'l')
		flags->mod_l = 1;
	else if (**dsc == 'j')
		flags->mod_j = 1;
	else if (**dsc == 'z')
		flags->mod_z = 1;
}
