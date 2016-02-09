/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 13:53:08 by azaha             #+#    #+#             */
/*   Updated: 2016/01/19 14:37:14 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char			*ft_itoa(int n)
{
	int		index;
	char	*rez;
	long	nb;
	long	sign;

	nb = n;
	index = 0;
	if ((sign = nb) < 0)
		nb = -nb;
	rez = (char*)malloc(sizeof(char) * (ft_nbr_len(nb) + 1));
	if (nb == 0)
		rez[index] = '0';
	else
		while (nb > 0)
		{
			rez[index] = nb % 10 + '0';
			nb = nb / 10;
			index++;
		}
	if (sign < 0)
		rez[index] = '-';
	rez[index + 1] = '\0';
	ft_strrev(rez);
	return (rez);
}
