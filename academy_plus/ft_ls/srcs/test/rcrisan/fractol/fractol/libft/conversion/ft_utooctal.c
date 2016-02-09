/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utooctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:14:14 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/15 17:25:50 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utooctal(unsigned long long n)
{
	char				*octal;
	int					length;
	unsigned long long	copy;

	copy = n;
	length = 1;
	while (copy > 7)
	{
		length++;
		copy /= 8;
	}
	octal = ft_strnew(length);
	while (length > 0)
	{
		length--;
		octal[length] = n % 8 + '0';
		n /= 8;
	}
	return (octal);
}
