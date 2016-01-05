/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 19:09:17 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/05 19:42:20 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_mod	check_flags(char *format)
{
	t_mod flag;
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			flag.procent = 1;
		i++;
	}
	return (flag);
}
