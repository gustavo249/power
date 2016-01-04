/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 01:06:20 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 02:55:49 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lines(char const *str, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
		{
			if (str[i] != c)
				words++;
		}
		else
		{
			if (str[i] != c && str[i - 1] == c)
				words++;
		}
		i++;
	}
	return (words);
}

static int		ft_getlen(char const *s, int i, char c)
{
	int		len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**copy;
	int		lines;
	int		i;

	lines = ft_lines(s, c);
	copy = (char**)malloc(sizeof(char*) * (lines + 1));
	if (copy)
	{
		i = 0;
		lines = 0;
		while (s[i] != '\0')
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
			{
				copy[lines] = ft_strsub(s, i, (size_t)ft_getlen(s, i, c));
				lines++;
			}
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		copy[lines] = 0;
	}
	return (copy);
}
