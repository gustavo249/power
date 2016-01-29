/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:24:57 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/29 18:45:30 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
# include "libft.h"

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			rows;
	int			cols;
	int			content_size;
	int			**matrix;
	int			error;
	char		**content;
}				t_mod;

#endif
