/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 19:19:15 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/06 19:29:43 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_specifier(char *choped, t_mod *mod)
{
	int i;

	i = 0;
	while (choped[i])
	{
		if (ft_strchr(SPECIFIERS, choped[i] != NULL))
		{
			if (choped[i] == 's')
				mod->specifier
		}
		i++;
	}
}
