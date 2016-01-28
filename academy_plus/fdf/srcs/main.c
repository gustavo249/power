/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:00:38 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/28 13:44:05 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_struct(t_mod *data)
{
	data->rows = 0;
	data->cols = 0;
}

void	read_matrix(int fd, t_mod *data)
{
	char	*line;
	char	**first_row;
	int		i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		first_row = ft_strsplit(line, ' ');
		while (first_row[i] != '\0')
		{
			printf("%s\tCOLS = %d\n", first_row[i], data->cols);
			data->cols++;
			i++;
		}
		data->rows++;
	}
}

int main (int argc, char **argv)
{
	t_mod	data;
	int		fd;

	if (argc != 2)
		return (-1);
	fd = open (argv[1], O_RDONLY);
	init_struct(&data);
	read_matrix(fd, &data);
	close(fd);
}
