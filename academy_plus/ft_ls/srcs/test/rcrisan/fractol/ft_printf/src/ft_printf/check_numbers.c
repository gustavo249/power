/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 17:28:53 by azaha             #+#    #+#             */
/*   Updated: 2016/01/20 21:32:47 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_numbers(char **dsc, t_flags *flags)
{
	if (ft_isdigit(**dsc))
	{
		flags->width = 0;
		while (ft_isdigit(**dsc))
		{
			flags->width = flags->width * 10 + (**dsc - '0');
			(*dsc)++;
		}
		(*dsc)--;
	}
	else if (**dsc == '.')
	{
		flags->dot = 1;
		(*dsc)++;
		flags->precision = 0;
		while (ft_isdigit(**dsc))
		{
			flags->precision = flags->precision * 10 + (**dsc - '0');
			(*dsc)++;
		}
		(*dsc)--;
	}
}
