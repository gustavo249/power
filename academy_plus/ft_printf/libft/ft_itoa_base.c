/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 12:12:54 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/22 16:27:00 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, int base)
{
	char	*str;
	char	*q;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(str) * 100);
	q = "0123456789abcdef";
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
