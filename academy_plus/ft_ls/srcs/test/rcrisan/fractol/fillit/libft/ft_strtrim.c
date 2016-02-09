/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 14:05:59 by azaha             #+#    #+#             */
/*   Updated: 2015/11/11 19:09:04 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s)
	{
		i = 0;
		k = 0;
		j = (int)ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (s[i] == '\0')
			return (ft_strdup(""));
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		ptr = (char*)malloc(sizeof(*ptr) * (j - i + 1));
		while (i <= j)
			ptr[k++] = s[i++];
		ptr[k] = '\0';
		return (ptr);
	}
	return (NULL);
}
