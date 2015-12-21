/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 14:04:10 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/05 15:06:49 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		validate_size(char *str)
{
	int chr;
	int lines;
	int i;

	chr = 0;
	lines = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			lines++;
			if (chr != 4 && lines != 5 )
				return (0);
			if (lines == 5 && chr != 0)
				return (0);
			chr = 0;
		}
		else
			chr++;
		i++;
	}
	if (lines != 5)
		return (0);
	return (1);
}
