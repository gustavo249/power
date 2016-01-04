/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 02:00:11 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 05:19:04 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long copy;

	copy = n;
	if (copy == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (copy < 0)
	{
		ft_putchar_fd('-', fd);
		copy *= -1;
	}
	if (copy > 9)
		ft_putnbr_fd(copy / 10, fd);
	ft_putchar_fd(copy % 10 + '0', fd);
}
