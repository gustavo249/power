/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:30:56 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/08 20:21:55 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		g_size;

int		is_flag(const char *format, int *k)
{
	int i;

	i = *k;
	if (strchr(FLAGS, format[i]) != NULL)
		return (1);
	return (0);
}

int		is_specifier(const char *format, int *k)
{
	int i;

	i = *k;
	if (strchr(SPECIFIERS, format[i]) != NULL)
		return (1);
	return (0);
}

char	*chop_format(const char *format, int *i)
{
	char	*choped;
	int		j;
	int		k;

	j = 0;
	k = *i;

	k++;
	choped = (char*)malloc(sizeof(choped) * strlen(format));
	while (format[k])
	{
		if (is_flag(format, &k) == 0 && is_specifier(format, &k) == 0)
			return (NULL);
		else if (is_specifier(format, &k))
		{
			choped[j] = format[k];
			break ;
		}
		else if (is_flag(format, &k))
			choped[j++] = format[k];
		k++;
	}
	return (choped);
}


t_mod	*process_flags(char *choped, t_mod *data)
{
	int i;

	i = 0;
	init_flags(data);
	while (choped[i])
	{
		if (choped[i] == '#')
			data->hash_mod = 1;
		else if (choped[i] == '0')
			data->zero_mod = 1;
		else if (choped[i] == '-')
			data->minus_mod = 1;
		else if (choped[i] == '+')
			data->plus_mod = 1;
		else if (choped[i] == ' ')
			data->space_mod = 1;
		i++;
	}
	process_mods(choped, data);
	process_precision(choped, data);
	return (data);
}

int		what_to_print(const char *format, va_list *arg)
{
	char	*text;
	char	*choped;
	t_mod	*data;
	int		i;

	i = -1;
	if (strchr(format, '%') == NULL)
			return (char*)(format);
	while (++i < strlen(format))
	{
		if (format[i] == '%')
		{
			choped = strdup(chop_format(format, &i));
			if (choped != NULL)
			{
				data = process_flags(choped, data);
				text = ft_strdup(convert_based_on_flags(data, arg));
				i = ft_strlen(choped) + i;
				printf("%s", text);
			}
		}
		else
			printf("%c", format[i]);
	}
	return (g_size);
}

int		ft_printf(const char *format, ...)
{
	va_list arg;
	int done;

	va_start(arg, format);
	done = what_to_print(format, &arg);
	va_end(arg);
	return (done);
}

int main ()
{
	ft_printf("mama%0#m.24d are mere");
//	t_mod flag;
	

/*	init_flags(&flag);
	
	printf("dot = %d\n", flag.dot_mod);
	printf("h mod = %d\n", flag.h_mod);
	printf("hh mod = %d\n", flag.hh_mod);
	printf("l mod = %d\n", flag.l_mod);
	printf("ll mod = %d\n", flag.ll_mod);
	printf("z mod = %d\n", flag.z_mod);
	printf("j mod = %d\n", flag.j_mod);
	printf("# mod = %d\n", flag.hash_mod);
	printf("minus mod = %d\n", flag.minus_mod);
	printf("0 mod = %d\n", flag.zero_mod);
	printf("+ mod = %d\n", flag.plus_mod);
	printf("space mod = %d\n", flag.space_mod);
	printf("identifier  = %d\n", flag.identifier);
	printf("width mod = %d\n", flag.width);
	printf("precision mod = %d\n", flag.precision);
	printf("procent mod = %d\n", flag.procent);
*/	return (0);
}
