/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 10:42:39 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/05 17:33:49 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#define BUFF_SIZE 5000

#include "fillit.h"

int main ()
{

	int k;
	int i;
	int j;
	char **matrix;
	char buff[BUFF_SIZE];
	int fd;
	int ret;

	k = 0;
	while (k < BUFF_SIZE)
	{
		buff[k] = 0;
		k++;
	}
	fd = open("fillit.sample", O_RDONLY);
	if (fd < 0)
	{
		printf("Open failed\n");
		return (1);
	}
	while ((ret = read(fd, buff, 21)))
	{
		if (ret < 0)
		{
			printf("Read failed\n");
			return (1);
		}
		matrix = create_matrix(buff);
		if (validate_map(matrix, buff) == 0)
		{
			printf("error\n");
			return (1);
		}
	}
	/*for (i = 0; i < 4; i++)
	  {
	  for (j = 0; j < 5; j++)
	  printf("%c", matrix[i][j]);
	  }*/
	printf("good");
	return (0);
}
