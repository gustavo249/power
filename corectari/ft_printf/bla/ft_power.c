/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 04:46:17 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 04:48:25 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int base, int exponent)
{
	int i;
	int	result;

	if (base == 0)
		return (0);
	if (exponent == 0)
		return (1);
	result = base;
	i = 2;
	while (i <= exponent)
	{
		result *= base;
		i++;
	}
	return (result);
}
