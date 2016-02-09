/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 15:07:46 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:38:01 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		len;
	int		index;
	char	temp;

	len = ft_strlen(str);
	index = 0;
	while (index < len / 2)
	{
		temp = str[index];
		str[index] = str[len - 1 - index];
		str[len - 1 - index] = temp;
		index++;
	}
	return (str);
}
