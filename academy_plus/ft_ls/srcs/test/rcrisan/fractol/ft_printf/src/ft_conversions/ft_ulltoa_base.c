/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 09:39:09 by azaha             #+#    #+#             */
/*   Updated: 2016/01/21 10:29:05 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(unsigned long long n, int base, char *table)
{
	int		i;
	char	sign;
	char	*aux;

	i = 0;
	sign = 0;
	aux = ft_strnew(32);
	if (n == 0)
		aux[0] = '0';
	while (n != 0)
	{
		aux[i++] = table[ft_abs(n % base)];
		n /= base;
	}
	aux = ft_strrev(aux);
	return (aux);
}
