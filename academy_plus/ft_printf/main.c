/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:30:56 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/05 19:46:50 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main ()
{
	t_mod flag;
	char *format = "mama are mere";

	flag = check_flags(format);
	ft_printf_noflags(format, flag);
	printf("\n%d\n", flag.procent);
	printf("%d", 42);
	return (0);
}
