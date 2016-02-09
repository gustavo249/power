/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:01:50 by azaha             #+#    #+#             */
/*   Updated: 2016/01/07 13:13:31 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	valid_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

int			check_line(char *line)
{
	if (ft_strlen(line) != 4)
		exit_program();
	if (!valid_line(line))
		exit_program();
	return (1);
}
