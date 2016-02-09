/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 22:04:18 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:25:28 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int k;

	num = 0;
	sign = 1;
	k = 0;
	while (str[k] == ' ' || str[k] == '\t' || str[k] == '\n' ||\
			str[k] == '\v' || str[k] == '\f' || str[k] == '\r')
		k++;
	if (str[k] == '-')
	{
		sign = -1;
		k++;
	}
	else if (str[k] == '+')
		k++;
	while (str[k] >= '0' && str[k] <= '9')
	{
		num = num * 10 + str[k] - '0';
		k++;
	}
	return (num * sign);
}
