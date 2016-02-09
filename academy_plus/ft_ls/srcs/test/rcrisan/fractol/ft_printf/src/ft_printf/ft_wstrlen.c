/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:08:47 by azaha             #+#    #+#             */
/*   Updated: 2016/01/22 13:09:26 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_wstrlen(wchar_t *str)
{
	int				i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		len += get_wchar_len(str[i]);
		i++;
	}
	return (len);
}
