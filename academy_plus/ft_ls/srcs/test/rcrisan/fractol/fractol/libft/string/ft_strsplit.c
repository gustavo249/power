/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 13:13:44 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/04 13:40:14 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int		fill_tab(char **tab, const char *s, char c)
{
	size_t	pos;
	size_t	wlen;
	size_t	i;

	i = 0;
	pos = 0;
	while (s[i] != '\0')
	{
		if (*(unsigned char*)(s + i) == (unsigned char)c)
			i++;
		else
		{
			wlen = 0;
			while (*(unsigned char*)(s + i + wlen) != (unsigned char)c &&
					*(unsigned char*)(s + i + wlen) != '\0')
				wlen++;
			tab[pos] = ft_strnew(wlen);
			if (tab[pos] == NULL)
				return (0);
			ft_strncpy(tab[pos], s + i, wlen);
			i += wlen;
			pos++;
		}
	}
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		words;

	words = count_words(s, c);
	tab = (char**)malloc(sizeof(char*) * (words + 1));
	if (tab == NULL)
		return (NULL);
	tab[words] = 0;
	if (fill_tab(tab, s, c) == 0)
		return (NULL);
	return (tab);
}
