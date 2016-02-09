/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utobin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:13:27 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/15 17:27:09 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utobin(unsigned long long n)
{
	char				*binary;
	int					length;
	unsigned long long	copy;

	copy = n;
	length = 1;
	while (copy > 1)
	{
		length++;
		copy /= 2;
	}
	binary = ft_strnew(length);
	while (length > 0)
	{
		length--;
		binary[length] = n % 2 + '0';
		n /= 2;
	}
	return (binary);
}
