/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 15:59:34 by jfazakas          #+#    #+#             */
/*   Updated: 2015/10/31 17:38:48 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		begin;
	int		end;

	if (!s)
		return (NULL);
	begin = 0;
	while ((s[begin] == ' ' || s[begin] == '\t' || s[begin] == '\n')
			&& s[begin] != '\0')
		begin++;
	if (s[begin] == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s);
	while (s[end - 1] == ' ' || s[end - 1] == '\t' || s[end - 1] == '\n')
		end--;
	return (ft_strsub(s, begin, end - begin));
}
