/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 21:41:28 by jfazakas          #+#    #+#             */
/*   Updated: 2015/12/18 22:23:04 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	double_get_digits(long double number,
					char *second_part, int precision)
{
	int		index;
	int		boolean;

	index = 0;
	while (index < precision)
	{
		number = (number - (long long)number) * 10;
		second_part[index + 1] = '0' + (int)number;
		index++;
	}
	number = (number - (long long)number) * 10;
	if (number >= 5)
	{
		boolean = 1;
		while (index >= 0 && boolean)
		{
			second_part[index]++;
			if (second_part[index] == '9' + 1)
				second_part[index] = '0';
			else
				boolean = 0;
			index--;
		}
	}
}

static char	*double_get_string(long long first_part,
					char *second_part, int negative_boolean, int precision)
{
	char	*string;

	if (second_part[0] == '.' + 1)
	{
		second_part[0] = '.';
		first_part++;
	}
	if (negative_boolean)
		first_part *= (-1);
	if (precision == 0)
		return (ft_lltoa(first_part));
	string = ft_strjoin(ft_lltoa(first_part), second_part);
	return (string);
}

char		*ft_dtoa(long double number, int precision)
{
	char		*string;
	int			negative_boolean;
	long long	first_part;
	char		*second_part;

	negative_boolean = 0;
	if (number < 0)
	{
		number *= (-1);
		negative_boolean = 1;
	}
	first_part = (long long)number;
	second_part = ft_strnew(precision + 1);
	second_part[0] = '.';
	double_get_digits(number, second_part, precision);
	string = double_get_string(first_part,
			second_part, negative_boolean, precision);
	return (string);
}
