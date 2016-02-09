/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 19:47:43 by azaha             #+#    #+#             */
/*   Updated: 2016/01/07 14:37:16 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_n(int count)
{
	int		i;

	i = 1;
	while (i * i < count * 4)
		i++;
	return (i);
}

void	fillit(void)
{
	char		**mat;
	int			n;

	g_viz = create_matrix(13);
	n = get_n(count_shapes(g_shapes));
	mat = create_matrix(n + 2);
	init_matrix(mat, n + 2);
	while (1)
		back(mat, n++, 0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**shapes;

	if (!(shapes = (char**)malloc(sizeof(char*) * 27)))
		exit_program();
	fd = open(argv[1], O_RDONLY);
	if (argc == 2 && check_fd(fd) == 1)
	{
		g_shapes = get_shapes(fd, shapes);
		fillit();
	}
	else
		exit_program();
	close(fd);
	return (0);
}
