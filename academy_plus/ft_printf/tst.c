/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:20:57 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/13 13:47:35 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main (int argc, char **argv)
{
	argc = argc + 1 - 1;
	printf(argv[1], ft_atoi(argv[2]));
	printf("\n");
	ft_printf(argv[1], ft_atoi(argv[2]));
	return (0);
}
