/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 12:47:17 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/22 16:26:39 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*n_is_zero(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static void		smaller_than_zero(char *str, int n, int *i)
{
	if (n < 0)
	{
		str[0] = '-';
		*i = *i + 1;
	}
}

char			*ft_itoa(int n)
{
	int		i;
	char	*s;

	i = ft_nr_cifre(n);
	s = (char*)malloc(sizeof(s) * i + 2);
	if (n == 0)
		return (n_is_zero(s));
	else if (n < 0)
		smaller_than_zero(s, n, &i);
	s[i--] = '\0';
	while (n)
	{
		if (n % 10 < 0)
			s[i] = -(n % 10) + '0';
		else
			s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (s);
}
