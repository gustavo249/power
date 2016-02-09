/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 14:06:34 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/04 19:35:03 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_numlen(long long n)
{
	unsigned int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n /= (-10);
		length += 2;
	}
	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}
