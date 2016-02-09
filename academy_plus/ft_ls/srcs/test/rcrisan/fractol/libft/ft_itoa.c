/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 13:53:08 by azaha             #+#    #+#             */
/*   Updated: 2015/11/08 17:24:02 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_length(int n)
{
	int		length;

	length = 0;
	while (n > 0)
	{
		length++;
		n /= 10;
	}
	return (length + 1);
}

static void		ft_reverse(char *s)
{
	int		start;
	int		end;
	char	aux;

	start = 0;
	end = ft_strlen(s) - 1;
	while (start < end)
	{
		aux = s[start];
		s[start] = s[end];
		s[end] = aux;
		start++;
		end--;
	}
}

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
	rez = (char*)malloc(sizeof(char) * (ft_length(nb) + 1));
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
	ft_reverse(rez);
	return (rez);
}
