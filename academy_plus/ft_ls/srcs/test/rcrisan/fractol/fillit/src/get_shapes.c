/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shapes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 19:49:13 by azaha             #+#    #+#             */
/*   Updated: 2016/01/07 13:25:34 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	gnl(char **shapes, char *tetriminos, int *index, int fd)
{
	int		ok;
	int		res;
	int		count;
	char	*line;

	ok = 1;
	count = 1;
	line = ft_strdup("");
	while ((res = get_next_line(fd, &line)) || ok)
	{
		if (count % 5 == 0)
		{
			if (res != 0)
				check_newline(line);
			process_tetriminos(&shapes[*index], tetriminos);
			(*index)++;
			free(tetriminos);
			tetriminos = ft_strdup("");
		}
		else if (check_line(line))
			tetriminos = save_line(tetriminos, line);
		if (res == 0)
			ok = 0;
		count++;
	}
}

char			**get_shapes(int fd, char **shapes)
{
	char	*tetriminos;
	int		index;

	index = 0;
	tetriminos = ft_strdup("");
	gnl(shapes, tetriminos, &index, fd);
	if (index > 26)
		exit_program();
	shapes[index] = 0;
	return (shapes);
}
