/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 15:32:48 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:34:02 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int		index;

	ft_strlowcase(str);
	index = 0;
	while (str[index] != '\0')
	{
		if (ft_isalpha(str[index]))
		{
			if (index == 0)
				str[index] = ft_toupper(str[index]);
			else if (!ft_isalnum(str[index - 1]))
				str[index] = ft_toupper(str[index]);
		}
		index++;
	}
	return (str);
}
