/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:02:21 by azaha             #+#    #+#             */
/*   Updated: 2015/12/23 22:50:18 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*save_line(char *tetriminos, char *line)
{
	char *aux;

	aux = ft_strjoin(tetriminos, line);
	aux = ft_strjoin(aux, "*");
	free(tetriminos);
	tetriminos = aux;
	return (tetriminos);
}
