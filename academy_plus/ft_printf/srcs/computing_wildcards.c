/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computing_wildcards.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:22:00 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/22 15:23:57 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*stock_wild_width(t_mod *data, int size)
{
	char	*width;
	int		i;
	int		len;
	int		k;
	int		p_size;

	if (size == 0)
		return ("");
	else if (size < 0)
		size = size * (-1);
	i = 0;
	len = 0;
	k = ft_strlen(data->result);
	width = ft_memalloc(size);
	p_size = data->wld_psize;
	if (data->result[0] == '\0')
		k++;
	if (p_size >= k && p_size > 0 && !no_strings(data))
		len = size - p_size;
	else
		len = size - k;
	if (len > 0)
		width = stock_damn_width(width, len);
	return (width);
}

char	*stock_wild_precision(t_mod *data, int size)
{
	int		len;
	char	*tmp;
	int		i;

	if (size < 0)
		size = 0;
	i = 0;
	len = 0;
	tmp = ft_memalloc(size + 10);
	if (ft_strchr(data->result, '-'))
		len = size - ft_strlen(data->result) + 1;
	else
		len = size - ft_strlen(data->result);
	if (len > 0)
	{
		while (len > 0)
		{
			tmp[i++] = '0';
			len--;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}

void	compute_wild_precision(t_mod *data, char *precizie)
{
	if (ft_strchr(data->result, '-'))
	{
		make_positive(data);
		precizie = ft_strjoin("-", precizie);
	}
	data->result = ft_strjoin(precizie, data->result);
	if (data->specifier == 'p')
		data->result = ft_strjoin("0x", data->result);
}

void	edit_wild_strings(t_mod *data)
{
	int		p_size;
	int		len;
	char	*aux;

	p_size = data->wld_psize;
	if (p_size == 0)
		data->result = ft_strdup("");
	else if (p_size < 0)
		p_size = p_size * (-1);
	len = (int)ft_strlen(data->result);
	aux = ft_memalloc(len);
	if (p_size < len)
	{
		aux = ft_strncpy(aux, data->result, p_size);
		data->result = ft_strdup("");
		data->result = ft_strdup(aux);
	}
}

void	compute_wild_width(t_mod *data, char *width)
{
	if (ft_strchr(data->result, '+') && data->zero_mod == 1)
	{
		make_positive(data);
		width = ft_strjoin("+", width);
	}
	if (data->wld_wsize < 0 || (data->specifier == 'p' && \
				data->zero_mod == 1 && data->result[0] == '0'))
		data->result = ft_strjoin(data->result, width);
	else
		data->result = ft_strjoin(width, data->result);
}
