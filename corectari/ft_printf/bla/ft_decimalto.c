/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimalto.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 04:04:24 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 05:21:06 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_decimalto(char *number, int result_base)
{
	int		decimal_integer;
	int		rest;
	char	*result;
	char	hex_char;

	result = (char*)malloc(sizeof(char) * 1000);
	decimal_integer = ft_atoi(number);
	while (decimal_integer)
	{
		rest = decimal_integer % result_base;
		hex_char = ft_rest(rest);
		result = ft_add_digit(result, hex_char);
		decimal_integer /= result_base;
	}
	return (result);
}
