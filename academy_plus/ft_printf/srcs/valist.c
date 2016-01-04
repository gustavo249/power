/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:34:19 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/04 19:29:26 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	arg(char *ftm, ...)
{
	va_list ap, ap2;
	int d;
	char c, *s;

	va_start(ap, ftm);
	va_copy(ap2, ap);
	while (*ftm)
	{
		switch (*ftm++)
		{
			case 's':
				s = va_arg(ap, char*);
				printf("string %s\n", s);
				break;
			case 'd':
				d = va_arg(ap, int);
				printf("int %d\n", d);
				break;
			case 'c':
				c = va_arg(ap, int);
			  	printf("%c\n", c);
				break;
		}
	}
	va_end(ap);
	va_end(ap2);
}
