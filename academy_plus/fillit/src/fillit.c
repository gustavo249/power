/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:16:24 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 14:16:27 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static int		check_null(int i)
{
	static int	ok;

	if (!ok)
		ok = 0;
	if (ok == 0 && i != 0)
		ok++;
	if (ok == 0 && i == 0)
		error();
	else
		ok++;
	return (1);
}

t_trimino		*fillit(char *file, char *buf, int *end, t_trimino *tetriminos)
{
	int			fd;
	t_trimino	*tmp;
	int			i;

	if ((fd = open(file, O_RDONLY)) < 0)
		error();
	tmp = NULL;
	while ((i = read(fd, buf, BUFFER)) > 0 && check_null(i) == 1)
	{
		if (!tetriminos)
		{
			tetriminos = tetrimino_new(buf, NULL, end);
			tmp = tetriminos;
		}
		else
		{
			tmp->next = tetrimino_new(buf, tmp, end);
			tmp = tmp->next;
		}
		ft_bzero(buf, BUFFER + 1);
	}
	if (close(fd) == -1 || check_null(i) != 1)
		error();
	return (tetriminos);
}
