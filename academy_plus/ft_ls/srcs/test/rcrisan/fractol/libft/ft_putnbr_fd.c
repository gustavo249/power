/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 18:46:42 by azaha             #+#    #+#             */
/*   Updated: 2015/11/06 19:14:24 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		index;
	long	aux;
	char	position[11];

	index = 0;
	aux = n;
	if (aux == 0)
		ft_putchar_fd('0', fd);
	if (aux < 0)
	{
		ft_putchar_fd('-', fd);
		aux = -aux;
	}
	while (aux != 0)
	{
		position[index] = aux % 10 + '0';
		aux = aux / 10;
		index++;
	}
	index--;
	while (index >= 0)
	{
		ft_putchar_fd(position[index], fd);
		index--;
	}
}
