/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:19:20 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 14:19:22 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int	tetrimino_count(t_trimino *tetriminos)
{
	int			nb;
	t_trimino	*current;

	current = tetriminos;
	if (current)
	{
		nb = 1;
		while (current->next)
		{
			nb++;
			current = current->next;
		}
		return (nb);
	}
	return (0);
}
