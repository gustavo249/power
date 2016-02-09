/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:02:38 by azaha             #+#    #+#             */
/*   Updated: 2016/01/18 14:18:35 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_flags(char **dsc, t_flags *flags)
{
	if (**dsc == '#')
		flags->hash = 1;
	if (**dsc == '0')
		flags->zero = 1;
	if (**dsc == '+')
		flags->plus = 1;
	if (**dsc == '-')
		flags->minus = 1;
	if (**dsc == ' ')
		flags->space = 1;
}
