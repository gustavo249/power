/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:00:38 by rcrisan           #+#    #+#             */
/*   Updated: 2016/02/03 17:16:52 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_mod	data;
	int		fd;

	if (argc != 2)
	{
		ft_putstr("No input file or too many files given\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror(argv[1]);
		return (-1);
	}
	init_struct(&data);
	if (read_matrix(fd, &data) < 0)
	{
		ft_putstr("Invalid map\n");
		return (-1);
	}
	draw_map(&data);
	close(fd);
	return (0);
}
