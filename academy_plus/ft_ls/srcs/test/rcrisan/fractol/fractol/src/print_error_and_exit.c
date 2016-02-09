/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_and_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 14:31:06 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/16 23:06:07 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_error_and_exit(void)
{
	ft_putendl("usage: ./fractol [ M | J | K | H | D ]");
	exit(1);
}
