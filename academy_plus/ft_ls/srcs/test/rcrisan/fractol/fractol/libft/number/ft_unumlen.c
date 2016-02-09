/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 08:57:54 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/07 08:58:26 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_unumlen(unsigned long long n)
{
	int		length;

	length = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}
