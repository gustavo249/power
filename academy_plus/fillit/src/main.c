/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:16:35 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 14:16:37 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int	main(int argc, char **argv)
{
	t_trimino	*tetriminos;
	t_map		*map;
	char		buf[BUFFER + 1];
	int			end;

	end = 1;
	if (argc != 2)
		error();
	ft_bzero(buf, BUFFER + 1);
	tetriminos = NULL;
	tetriminos = fillit(argv[1], buf, &end, tetriminos);
	tetrimino_clean(tetriminos);
	if (end == 0)
		error();
	map = map_new();
	if (tetrimino_count(tetriminos) > 26)
		error();
	map_solve(map, tetriminos);
	map_view(map);
	return (0);
}
