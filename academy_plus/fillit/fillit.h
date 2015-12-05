/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 14:12:12 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/05 14:40:31 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>

char    **create_matrix(char *str);
int     validate_map(char **matrix, char *str);
int     validate_size(char *str);
int		validate_content(char **matrix);

#endif
