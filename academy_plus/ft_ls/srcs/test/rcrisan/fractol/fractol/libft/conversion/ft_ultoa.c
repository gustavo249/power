/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 18:31:35 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/16 18:31:36 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa(unsigned long n)
{
	char	*s;
	int		len;

	len = ft_unumlen(n);
	s = ft_strnew(len);
	if (s == NULL)
		return (NULL);
	len--;
	while (len >= 0)
	{
		s[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (s);
}
