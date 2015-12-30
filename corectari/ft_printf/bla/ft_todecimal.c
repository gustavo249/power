/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_todecimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 03:59:47 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 04:56:45 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_todecimal(char *number, int base)
{
	int i;
	int digit;
	int decimal;

	decimal = 0;
	i = 0;
	while (number[i + 1])
		i++;
	while (i >= 0)
	{
		digit = ft_chartoint(number[i]);
		decimal = decimal + (digit * ft_power(base, ft_strlen(number) - i - 1));
		i--;
	}
	number = ft_itoa(decimal);
	return (number);
}
