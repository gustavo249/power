/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 18:31:21 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/16 18:31:22 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_lltoa(long long n)
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
