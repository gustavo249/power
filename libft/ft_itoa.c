/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acovaciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 01:47:58 by acovaciu          #+#    #+#             */
/*   Updated: 2015/11/10 15:13:53 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		ft_nrcifre(int n)
{
	int nr;

	nr = 0;
	while (n != 0)
	{
		nr++;
		n /= 10;
	}
	return (nr);
}

static	char	*ft_strrev(char *str)
{
	int		counter;
	int		size_str;
	char	temp;

	counter = 0;
	if (str[counter] == '-')
		counter++;
	size_str = 0;
	while (str[size_str])
		size_str++;
	size_str -= 1;
	while (counter < size_str)
	{
		temp = str[size_str];
		str[size_str] = str[counter];
		str[counter] = temp;
		counter++;
		size_str--;
	}
	return (str);
}

int				ft_valoarej(int n)
{
	if (n < 0)
		return (ft_nrcifre(n) + 2);
	return (ft_nrcifre(n) + 1);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (n == 0)
		return ("0\0");
	if (n < 0)
	{
		str = (char*)malloc(sizeof(str) * ft_nrcifre(n) + 2);
		str[i++] = '-';
	}
	else
		str = (char*)malloc(sizeof(str) * ft_nrcifre(n) + 1);
	j = ft_valoarej(n);
	str[j] = '\0';
	while (i < j && n != 0)
	{
		str[i] = n % 10 + '0';
		if (n < 0)
			str[i] = -(n % 10) + '0';
		n = n / 10;
		i++;
	}
	return (ft_strrev(str));
}
