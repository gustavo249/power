/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:19:52 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 14:19:54 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	tetrimino_print(t_trimino *tetrimino)
{
	int	i;

	i = 0;
	while (tetrimino->cases[i])
	{
		ft_putchar(tetrimino->cases[i]);
		if ((i + 1) % 4 == 0)
			ft_putchar('\n');
		i++;
	}
}

void	tetrimino_view(t_trimino *tetriminos)
{
	t_trimino	*lst;

	lst = tetriminos;
	while (lst)
	{
		tetrimino_print(lst);
		ft_putnbr(tetrimino_pos(lst));
		lst = lst->next;
	}
	free(lst);
}

void	tetrimino_viewr(t_trimino *tetriminos)
{
	t_trimino	*lst;

	lst = tetriminos;
	while (lst)
	{
		tetrimino_print(lst);
		lst = lst->prev;
	}
}
