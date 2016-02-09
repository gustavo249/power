/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 22:04:27 by azaha             #+#    #+#             */
/*   Updated: 2016/01/13 16:56:38 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	save_row(t_env *e, int row, char *line)
{
	int		column;
	float	this_row;
	char	**numbers;

	column = 0;
	this_row = -(e->map_config->rows - 1) / 2 + row;
	numbers = ft_strsplit(line, ' ');
	while (column < e->map_config->columns)
	{
		e->map[row][column].x = -(e->map_config->columns - 1) / 2 + column;
		e->map[row][column].y = this_row;
		e->map[row][column].z = ft_atoi(numbers[column]);
		column++;
	}
}

void			get_coordinates(t_env *e)
{
	int		fd;
	int		row;
	char	*line;

	row = 0;
	fd = open(e->file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		save_row(e, row, line);
		row++;
	}
	close(fd);
}
