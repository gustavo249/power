/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computing_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:37:36 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/22 15:39:20 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_positive(t_mod *data)
{
	int		i;
	char	*positive;

	i = 0;
	positive = ft_memalloc(ft_strlen(data->result));
	while (data->result[i])
	{
		if (data->result[i] == '-' || data->result[i] == '+')
			break ;
		i++;
	}
	positive = ft_strcpy(positive, data->result + i + 1);
	free(data->result);
	data->result = ft_strdup(positive);
}

void	compute_precision(t_mod *data)
{
	if (ft_strchr(data->result, '-'))
	{
		make_positive(data);
		data->precizie = ft_strjoin("-", data->precizie);
	}
	data->result = ft_strjoin(data->precizie, data->result);
	if (data->specifier == 'p')
		data->result = ft_strjoin("0x", data->result);
}

void	compute_width(t_mod *data)
{
	if (ft_strchr(data->result, '+') && data->zero_mod == 1)
	{
		make_positive(data);
		data->lungime = ft_strjoin("+", data->lungime);
	}
	if (data->minus_mod == 1 || (data->specifier == 'p' && \
				data->zero_mod == 1 && data->result[0] == '0'))
		data->result = ft_strjoin(data->result, data->lungime);
	else
		data->result = ft_strjoin(data->lungime, data->result);
}

void	case_plus(t_mod *data)
{
	if (data->specifier == 'd' || data->specifier == 'i' || \
			data->specifier == 'D')
	{
		if (ft_strchr(data->result, '-') == NULL)
			data->result = ft_strjoin("+", data->result);
	}
}

void	case_hash(t_mod *data)
{
	int len;
	int	p_size;

	len = (int)ft_strlen(data->result);
	p_size = (int)ft_strlen(data->precizie);
	if (data->specifier == 'x' && data->result[len - 1] != '0')
		data->result = ft_strjoin("0x", data->result);
	else if (data->specifier == 'X' && data->result[len - 1] != '0')
		data->result = ft_strjoin("0X", data->result);
	else if ((data->specifier == 'o' || data->specifier == 'O') && \
			data->result[0] != '0')
	{
		data->result = ft_strjoin("0", data->result);
	}
}
