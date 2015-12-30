/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 00:29:27 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 05:15:46 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*result;
	int		i;
	int		j;

	if (!(result = (char*)malloc(sizeof(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	j = 0;
	while (s[i])
		result[j++] = s[i++];
	result[j] = '\0';
	j--;
	while (result[j] == '\t' || result[j] == '\n' || result[j] == ' ')
		result[j--] = '\0';
	return (result);
}
