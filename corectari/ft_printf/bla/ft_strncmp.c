/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 11:53:12 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 05:16:31 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((*(unsigned char*)(s1 + i)) != (*(unsigned char*)(s2 + i)))
			return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
		i++;
	}
	return (0);
}
