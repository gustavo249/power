/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rows_and_columns.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 21:35:21 by azaha             #+#    #+#             */
/*   Updated: 2016/01/13 17:06:55 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	check_validity(char *nbr)
{
	int i;

	i = 0;
	while (nbr[i] != '\0')
	{
		if (nbr[i] > '9' || nbr[i] < '0')
			exit_program();
		i++;
	}
}

void			check_nr_of_rows(t_env *e)
{
	if (e->map_config->rows == 0)
		exit_program();
}

void			get_rows_and_columns(t_env *e)
{
	int		fd;
	int		row_numbers;
	char	*line;
	char	**this_row;

	fd = open(e->file, O_RDONLY);
	e->map_config->rows = 0;
	e->map_config->columns = 0;
	while (get_next_line(fd, &line))
	{
		this_row = ft_strsplit(line, ' ');
		row_numbers = 0;
		while (this_row[row_numbers] != '\0')
		{
			check_validity(this_row[row_numbers]);
			row_numbers++;
		}
		if (e->map_config->columns == 0)
			e->map_config->columns = row_numbers;
		else if (e->map_config->columns != row_numbers)
			exit_program();
		e->map_config->rows++;
	}
	check_nr_of_rows(e);
	close(fd);
}
