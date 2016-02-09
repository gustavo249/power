/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:21:26 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/04 19:29:17 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ltoa(long n)
{
	char	*s;
	int		len;

	len = ft_numlen(n);
	s = ft_strnew(len);
	if (s == NULL)
		return (NULL);
	len--;
	if (n < 0)
	{
		s[len] = (10 - n % 10) % 10 + '0';
		s[0] = '-';
		len--;
		n = n / (-10);
	}
	while (len >= 0 && s[len] != '-')
	{
		s[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (s);
}
