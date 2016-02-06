/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 11:56:30 by rcrisan           #+#    #+#             */
/*   Updated: 2016/02/06 18:56:38 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	list_info(char	*name)
{	
	struct passwd	*id;
	struct group	*gr;
	struct stat		info;
	time_t 			t;
	char			*our_time;
	int r;

	r = stat(name, &info);
	our_time = malloc(100);
	if (r == 0)
	{
		id = getpwuid(info.st_uid);
		gr = getgrgid(info.st_gid);
		t = time(&info.st_mtime);
		our_time = ctime(&t);
		if (id->pw_name == NULL)
			printf("NULL PIZDA!\n");
		else
		{
			printf("NAME = %s\n", id->pw_name);
			printf("GROUP NAME = %s\n", gr->gr_name);	
			ft_putstr("\nnumber of hard links = ");
			ft_putnbr(info.st_nlink);
			ft_putstr("\ntotal size, in bytes = ");
			ft_putnbr(info.st_size);
			ft_putstr("\nTIME = ");
			ft_putstr(our_time);
		}
		printf("\n\nFILE = %s\n", name);
		ft_putstr("\nID of device containing file = ");
		ft_putnbr(info.st_dev);
		ft_putstr("\ninode number = ");
		ft_putnbr(info.st_ino);
		ft_putstr("\nprotection = ");
		ft_putnbr(info.st_mode);
		ft_putstr("\nuser ID of owner = ");
		ft_putnbr(info.st_uid);
		ft_putstr("\ngroup ID of owner = ");
		ft_putnbr(info.st_gid);
		ft_putstr("\ndevice ID (if special file) = ");
		ft_putnbr(info.st_rdev);
		ft_putstr("\nblocksize for filesystem I/O = ");
		ft_putnbr(info.st_blksize);
		ft_putstr("\nnumber of 512B blocks allocated = ");
		ft_putnbr(info.st_blocks);
		ft_putstr("\ntime of last access = ");
		ft_putnbr(info.st_atime);
		ft_putstr("\ntime of last data modification = ");
		ft_putnbr(info.st_mtime);
		printf("\n\n--------END FILE---------\n\n");
	}
	else
		ft_putstr("error\n");
}

int		main(int argc, char **argv)
{
	DIR				*fd;
	struct dirent	*buff;
	char 			*name;

	name = malloc(100);
	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	fd = opendir(argv[1]);
	if (fd == NULL)
	{
		perror(argv[1]);
	}
	else
	{
		while (1)
		{
			buff = readdir(fd);
			if (!buff)
				break;
			name = buff->d_name;
			list_info(name);
		}
		closedir(fd);
	}
	return (0);
}
