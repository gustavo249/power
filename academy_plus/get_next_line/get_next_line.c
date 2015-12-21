/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:10:57 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 19:00:10 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#define BUFF_SIZE 32


static int	read_untill(int const fd, char **file)
{
	char	*new_file;
	char	*buff;
	int		result;

	buff = (char*)malloc(sizeof(*buff) * (BUFF_SIZE + 1));
	if (!(buff))
		return (-1);
	result = read(fd, buff, BUFF_SIZE);
	while (result > 0)
	{
		buff[result] = '\0';
		new_file = ft_strjoin(*file, buff);
		free(*file);
		*file = new_file;
	}
	free(buff);
	return (result);
}

int			get_next_line(int const fd, char **line)
{
	static char	*text = NULL;
	int			result;
	char		*pos_n;
	
	if ((!(text) && (text = (char*)malloc(sizeof(*text))) == NULL) || !(line)
			|| BUFF_SIZE < 0 || fd < 0)
		return (-1);
	pos_n = ft_strchr(text, '\n');
	while (pos_n == NULL)
	{
		result = read_untill(fd, &text);
		if (result == 0)
		{
			if (ft_strlen(text) == 0)
				return (0);
			text = ft_strjoin(text, "\n");
		}
		if (result < 0)
			return (-1);
		else
			pos_n = ft_strchr(text, '\n');
	}
	*line = ft_strsub(text, 0, ft_strlen(text) - ft_strlen(pos_n));
	text = ft_strdup(pos_n + 1);
	return (1);
}

int main ()
{
	char *s;
	int fd;
	int line;

	fd = open("42.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd, &s)))
	{
		ft_putstr(s);
		ft_putchar('\n');
		free(s);
	}
	return (0);
}
