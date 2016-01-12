/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_baseUPP.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:02:19 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/12 16:06:58 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_utoa_baseUPP(unsigned int n, int base)
{
	char *str;
	char *q;
	int i;

	i = 0;
	str = (char*)malloc(sizeof(str) * 100);
	q = "0123456789ABCDEF";
	if (n == 0)
		return (ft_utoa(n));
	while (n)
	{
		str[i] = q[n % base];
		n = n / base;
		i++;
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
