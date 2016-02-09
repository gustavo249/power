/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 09:39:09 by azaha             #+#    #+#             */
/*   Updated: 2016/01/20 09:39:15 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa_base(long long n, int base, char *table)
{
	int		i;
	char	sign;
	char	*aux;

	i = 0;
	sign = 0;
	if (n < 0)
		sign = 1;
	aux = ft_strnew(32);
	if (n == 0)
		aux[0] = '0';
	while (n != 0)
	{
		aux[i++] = table[ft_abs(n % base)];
		n /= base;
	}
	if (sign && base == 10)
		aux[i] = '-';
	aux = ft_strrev(aux);
	return (aux);
}
