/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 14:12:07 by azaha             #+#    #+#             */
/*   Updated: 2015/11/26 15:39:50 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	read_to_stock(int const fd, char **stock)
{
	char	*buff;
	char	*temp;
	int		result;

	if (!(buff = (char*)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	result = read(fd, buff, BUFF_SIZE);
	if (result > 0)
	{
		buff[result] = '\0';
		temp = ft_strjoin(*stock, buff);
		free(*stock);
		*stock = temp;
	}
	free(buff);
	return (result);
}

int			get_next_line(int const fd, char **line)
{
	int			result;
	char		*end_of_line;
	static char	*stock = NULL;

	if (!stock)
		stock = (char*)malloc(sizeof(*stock));
	if (stock == NULL || !line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((end_of_line = ft_strchr(stock, '\n')) == NULL)
	{
		result = read_to_stock(fd, &stock);
		if (result == 0)
		{
			if (ft_strlen(stock) == 0)
				return (0);
			stock = ft_strjoin(stock, "\n");
		}
		if (result < 0)
			return (-1);
	}
	*line = ft_strsub(stock, 0, ft_strlen(stock) - ft_strlen(end_of_line));
	stock = ft_strdup(end_of_line + 1);
	return (1);
}
