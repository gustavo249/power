/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 18:44:57 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 05:14:06 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	sgn;
	char	*aux;
	int		i;

	i = 0;
	sgn = 0;
	if (n < 0)
		sgn = 1;
	aux = ft_strnew(15);
	if (n == 0)
		aux[0] = '0';
	while (n != 0)
	{
		aux[i++] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (sgn)
		aux[i] = '-';
	aux = ft_strrev(aux);
	return (aux);
}
