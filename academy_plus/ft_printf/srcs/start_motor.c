/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_motor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:54:55 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/22 15:15:09 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_mizerie(const char *format, unsigned long int *i, \
		t_mod *data, char *choped)
{
	int len;

	len = ft_strlen(choped);
	if ((ft_strchr(SPECIFIERS, choped[len - 1]) == NULL))
	{
		data->result[0] = format[*i + ft_strlen(choped) + 1];
		*i = *i + 1;
	}
}

void	start_engine(char *text, int *size, \
		t_mod *data, va_list *arg)
{
	text = ft_strdup(convert_based_on_flags(data, arg, size));
	*size = *size + how_much_to_print(text, data);
}

void	init_var(unsigned long int *i, int *size)
{
	*i = -1;
	*size = 0;
}

int		what_to_print(const char *format, va_list *arg)
{
	char				*text;
	int					size;
	char				*choped;
	t_mod				data;
	unsigned long int	i;

	text = NULL;
	init_var(&i, &size);
	while (++i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			choped = ft_strdup(chop_format(format, &i));
			process_flags(choped, &data);
			is_mizerie(format, &i, &data, choped);
			start_engine(text, &size, &data, arg);
			i = i + ft_strlen(choped);
		}
		else
		{
			ft_putchar(format[i]);
			size++;
		}
	}
	return (size);
}

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	int			done;

	done = 0;
	va_start(arg, format);
	if (no_procent(format))
		return (ft_strlen(format));
	done = what_to_print(format, &arg);
	va_end(arg);
	return (done);
}
