/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utohexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:15:33 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/16 18:24:57 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utohexa(unsigned long long n)
{
	char				*hexa;
	int					length;
	unsigned long long	copy;

	copy = n;
	length = 1;
	while (copy > 15)
	{
		length++;
		copy /= 16;
	}
	hexa = ft_strnew(length);
	while (length > 0)
	{
		length--;
		if (n % 16 > 9)
			hexa[length] = n % 16 + 'a' - 10;
		else
			hexa[length] = n % 16 + '0';
		n /= 16;
	}
	return (hexa);
}
