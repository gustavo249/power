/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:14:58 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/12 14:24:51 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nrcifre_unsigned(unsigned int n)
{
	int i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char     *n_is_zero(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char    *ft_utoa(unsigned int n)
{
	int i;
	char *s;

	i = nrcifre_unsigned(n);
	s = (char*)malloc(sizeof(s) * i + 2);
	if (n == 0)
		return (n_is_zero(s));
	s[i--] = '\0';
	while (n)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (s);
}
