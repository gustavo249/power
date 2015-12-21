/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 18:39:09 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/21 19:00:13 by rcrisan          ###   ########.fr       */
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

static int	read_buffer(int const fd, char **text)
{
	char	*buff;
	int		result;
	char	*new;

	buff = (char*)malloc(sizeof(*buff) * (BUFF_SIZE + 1));
	if (!(buff))
		return (-1);
	result = read(fd, buff, BUFF_SIZE);
	if (result > 0)
	{
		buff[result] = '\0';
		new = ft_strjoin(*text, buff);
		free(*text);
		*text = new;
	}
	free(buff);
	return (result);
}

int			get_next_line(int const fd, char **line)
{
	static char		*text = NULL;
	int				result;
	char			*n_poz;

	if ((!(text) && (text = (char*)malloc(sizeof(*text))) == NULL) || !(line)
			|| BUFF_SIZE < 0 || fd < 0)
		return (-1);
	n_poz = ft_strchr(text, '\n');
	while (n_poz == NULL)
	{
		result = read_buffer(fd, &text);
		if (result == 0)
		{
			if (ft_strlen(text) == 0)
				return (0);
			text = ft_strjoin(text, "\n");
		}
		if (result < 0)
			return (-1);
		else
			n_poz = ft_strchr(text, '\n');
	}
	*line = ft_strsub(text, 0, ft_strlen(text) - ft_strlen(n_poz));
	text = ft_strdup(n_poz + 1);
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
