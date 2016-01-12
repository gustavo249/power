/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:02:43 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/12 16:07:27 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(unsigned int n, int base)
{
	char *str;
	char *q;
	int i;

	i = 0;
	str = (char*)malloc(sizeof(str) * 150);
	q = "0123456789abcdef";
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
