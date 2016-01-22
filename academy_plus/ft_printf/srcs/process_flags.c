/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:51:39 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/22 15:53:13 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_dot_mod(char *choped, t_mod *data)
{
	int i;

	i = 0;
	while (choped[i])
	{
		if (choped[i] == '.' && (!ft_isdigit(choped[i + 1]) || \
					choped[i + 1] == '0') && choped[i + 1] != '*')
		{
			data->dot_mod = 1;
		}
		i++;
	}
}

void	process_wildcard(char *choped, t_mod *data)
{
	int i;

	i = 0;
	while (choped[i])
	{
		if (choped[i] == '*' && choped[i - 1] != '.')
			data->wild_width = 1;
		else if (choped[i] == '*' && choped[i - 1] == '.')
			data->wild_precision = 1;
		i++;
	}
}

void	process_flags(char *choped, t_mod *data)
{
	int i;

	i = -1;
	init_flags(data);
	while (choped[++i])
	{
		if (choped[i] == '#')
			data->hash_mod = 1;
		else if (choped[i] == '-')
			data->minus_mod = 1;
		else if (choped[i] == '+')
			data->plus_mod = 1;
		else if (choped[i] == '%')
			data->procent = 1;
		else if (choped[i] == ' ')
			data->space_mod = 1;
	}
	if (validate_mod(choped) > 0)
		process_mods(choped, data);
	data->choped = choped;
	process_precision(choped, data);
	process_specifiers(choped, data);
	process_dot_mod(choped, data);
	process_zero_mod(choped, data);
	process_wildcard(choped, data);
}

int		get_precision(char *choped)
{
	int		i;
	char	*precision;
	int		k;

	i = 0;
	k = 0;
	precision = (char*)malloc(sizeof(precision) * ft_strlen(choped));
	while (choped[i])
	{
		if (choped[i] == '.')
		{
			i++;
			while (choped[i] >= '0' && choped[i] <= '9')
				precision[k++] = choped[i++];
		}
		i++;
	}
	precision[k] = '\0';
	return (ft_atoi(precision));
}

int		get_width(char *choped)
{
	int		i;
	char	*width;
	int		k;
	int		ok;

	i = 0;
	k = 0;
	ok = 0;
	width = ft_memalloc(ft_strlen(choped));
	while (choped[i])
	{
		if (choped[i] == '.')
			ok = 1;
		if (choped[i] > '0' && choped[i] <= '9' && ok == 0)
		{
			while (ft_isdigit(choped[i]))
				width[k++] = choped[i++];
			break ;
		}
		i++;
	}
	return (ft_atoi(width));
}
