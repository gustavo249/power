/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_baseUPP.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:02:00 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/12 15:10:58 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_baseUPP(int n, int base)
{
	char *str;
	char *q;
	int i;

	i = 0;
	str = (char*)malloc(sizeof(str) * 100);
	q = "0123456789ABCDEF";
	if (n <= 0)
		return (ft_itoa(n));
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
