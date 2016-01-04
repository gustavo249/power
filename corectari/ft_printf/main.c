/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anflorea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:04:28 by anflorea          #+#    #+#             */
/*   Updated: 2015/12/18 20:13:27 by anflorea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	//long	i;
	//char	*s;
	//wchar_t	wc;
	//int		aux;

	//i =  0;
	//ft_printf("%-30s: %s\n", "This is a test", "test");
	//printf("%-30s: %s\n", "This is a test", "test");
	//ft_printf("%dasdf%10d%%%#0-+2000.20hdqwd%hll%+#lld%21203.3lc%02hhSas", 10, 20);
	//i = printf("%0.3.jdaa", i);
	//printf("\n\ni: %d", i);
	//printf("% 5s", "sad");
	//s = NULL;
	//wc = L'吉';
	//ft_printf("%-+10.0f\n", -1.5);
	//ft_printf("12345678  %n\n", &aux);
	//ft_printf("%d\n", aux);
	//printf("%C\n", wc);
	int a;
	a = 42;
	printf("%+d\n", a);
	ft_printf("%+d\n", a);
	return (0);
}
