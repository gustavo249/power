/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 04:52:06 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 05:15:02 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_digit(char *src, char digit)
{
	char	*result;
	int		i;

	result = (char*)malloc(sizeof(*src) * ft_strlen(src) + 2);
	i = 0;
	result[0] = digit;
	while (src[i])
	{
		result[i + 1] = src[i];
		i++;
	}
	return (result);
}
