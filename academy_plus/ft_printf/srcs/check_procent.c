/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_procent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 11:56:36 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/06 12:11:13 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_procent(char *format, t_mod *flag)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			flag->procent = 1;
		i++;
	}
}
