/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:19:31 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 14:19:32 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static int	validchar(char c)
{
	if (c == '.')
		return (1);
	else if (c == '#')
		return (2);
	return (0);
}

static int	checkstr(char *str)
{
	int	i;
	int	valid;
	int	full;
	int	line;

	i = 0;
	valid = 0;
	full = 0;
	line = 0;
	while (str[i])
	{
		if (validchar(str[i]) == 2)
		{
			full++;
			valid++;
		}
		else if (validchar(str[i]))
			valid++;
		else if (str[i] == '\n' && ((i + 1) % 5 == 0))
			line++;
		i++;
	}
	if (valid == 16 && full == 4 && line == 4)
		return (1);
	return (0);
}

static char	*cleanstr(char *str, int *end)
{
	char	**tab;
	char	*out;
	int		i;

	*end = 1;
	i = ft_strlen(str);
	if (str[i - 2] == '\n')
		*end = 0;
	i = 0;
	out = (char*)ft_memalloc(4 * 4 + 1);
	ft_bzero(out, (4 * 4 + 1));
	tab = ft_strsplit(str, '\n');
	while (tab[i])
	{
		out = ft_strjoin(out, tab[i]);
		i++;
	}
	return (out);
}

t_trimino	*tetrimino_new(char *str, t_trimino *prev, int *end)
{
	t_trimino	*elem;

	elem = NULL;
	if (!checkstr(str))
		error();
	elem = malloc(sizeof(t_trimino));
	if (!elem)
		error();
	elem->cases = ft_strdup(cleanstr(str, end));
	elem->x = -1;
	elem->y = -1;
	if (prev != NULL)
		elem->prev = prev;
	else
	{
		elem->next = NULL;
		elem->prev = NULL;
	}
	tetrimino_check_collide(elem);
	return (elem);
}
