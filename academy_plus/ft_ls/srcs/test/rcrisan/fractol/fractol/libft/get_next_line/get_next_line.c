/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 17:50:08 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/04 13:35:48 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	copy_to_line(char **line, char *source, int new_size)
{
	char	*new_memory;
	int		old_size;
	int		index;

	old_size = ft_strlen(*line);
	if (!(new_memory = ft_strnew(old_size + new_size)))
		return (-1);
	index = 0;
	while (index < old_size)
	{
		new_memory[index] = (*line)[index];
		index++;
	}
	index = 0;
	while (index < new_size)
	{
		new_memory[old_size + index] = source[index];
		index++;
	}
	ft_strdel(line);
	*line = new_memory;
	return (1);
}

static int	select_and_copy(char **line,
		char *source, int *eol_boolean)
{
	int		new_size;

	new_size = 0;
	while (source[new_size] != '\0' && source[new_size] != '\n')
		new_size++;
	if (copy_to_line(line, source, new_size) == -1)
		return (-1);
	if (source[new_size] == '\n')
		*eol_boolean = 1;
	return (new_size);
}

static int	save_and_exit(char **save, char *source, int used_size)
{
	char	*temp;

	temp = ft_strdup(source + used_size + 1);
	if (!temp)
		return (-1);
	ft_strdel(save);
	*save = temp;
	return (1);
}

int			get_that_line(int const fd, char **line, char **save)
{
	char	*buffer;
	int		new_size;
	int		eol_boolean;
	long	read_return;

	eol_boolean = 0;
	*line = ft_strdup("");
	if ((new_size = select_and_copy(line, *save, &eol_boolean)) == -1)
		return (-1);
	if (eol_boolean == 1)
		return (save_and_exit(save, *save, new_size));
	buffer = ft_strnew(BUFF_SIZE);
	while (!eol_boolean)
	{
		ft_strclr(buffer);
		read_return = read(fd, buffer, BUFF_SIZE);
		if (read_return == -1 || read_return == 0)
			return (read_return);
		if (read_return < BUFF_SIZE)
			if (*(ft_strchr(buffer, 0) - 1) != '\n')
				buffer[ft_strlen(buffer)] = '\n';
		if ((new_size = select_and_copy(line, buffer, &eol_boolean)) == -1)
			return (-1);
	}
	return (save_and_exit(save, buffer, new_size));
}

int			get_next_line(int const fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*node;
	char			*exception;

	if (fd < 0 || !line)
		return (-1);
	exception = ft_strdup("");
	if (fd == 0)
		return (get_that_line(fd, line, &exception));
	node = list;
	while (node && node->FILE_DESCRIPTOR != (unsigned int)fd)
		node = node->next;
	if (!node)
	{
		node = (t_list*)malloc(sizeof(t_list));
		if (node == NULL)
			return (-1);
		node->next = NULL;
		node->SAVE = ft_strdup("");
		node->FILE_DESCRIPTOR = fd;
		ft_lstadd(&list, node);
	}
	if (!list)
		list = ft_lstnew(ft_strdup(""), fd);
	return (get_that_line(fd, line, (char**)&(node->SAVE)));
}
