/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertfromto.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 04:07:22 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 05:21:49 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convertfromto(char *number, int base, int result_base)
{
	char *result;

	if (base == 10)
		result = ft_decimalto(number, result_base);
	else
	{
		number = ft_decimalto(number, base);
		result = ft_decimalto(number, result_base);
	}
	return (result);
}
