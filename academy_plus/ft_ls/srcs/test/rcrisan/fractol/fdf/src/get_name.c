/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 22:40:17 by azaha             #+#    #+#             */
/*   Updated: 2016/01/10 22:44:29 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*get_name(char *path)
{
	int	index;
	int	count;

	index = ft_strlen(path);
	while (index > 0 && path[index - 1] != '/')
		index--;
	count = 0;
	while (path[index + count] != '.' && path[index + count] != '\0')
		count++;
	return (ft_strsub(path, index, count));
}
