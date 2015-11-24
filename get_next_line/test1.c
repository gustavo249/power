/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:13:22 by rcrisan           #+#    #+#             */
/*   Updated: 2015/11/24 18:22:43 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include <stdio.h>

#define BUFF_SIZE 10000

char		*create_string(char *string, int fd)
{
	char *temp;
	int ret;

	ret = read(fd, string, BUFF_SIZE);
	temp = (char*)malloc(sizeof(*string) * BUFF_SIZE);
	ft_putstr(string);
	if (ret > 0)
	{
		string[ret] = '\0';
		temp = ft_strdup(string);
		free(string);
	}
	//ft_putstr(temp);
	return (temp);
}

int main ()
{
	int fd;
	char buff[BUFF_SIZE + 1];
	int ret;
	
	fd = open("42", O_RDONLY | O_CREAT);
	if (fd < 0)
	{
		ft_putstr("open(): failed");
		return (0);
	}
	create_string(buff, fd);
	if (close(fd) < 0)
	{
		ft_putstr("close(): failed");
		return (0);
	}
	return (0);
}
