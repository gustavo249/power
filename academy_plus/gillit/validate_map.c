/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 14:09:15 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/05 16:37:39 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		validate_map(char **matrix, char *str)
{
	if (validate_content(matrix) == 0 || validate_size(str) == 0)
		return (0);
	return (1);
}
