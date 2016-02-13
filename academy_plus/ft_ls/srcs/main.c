/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:09:04 by rcrisan           #+#    #+#             */
/*   Updated: 2016/02/13 20:18:16 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

p_list	*add_link(p_list *list, char *data)
{
	p_list *new;

	new = malloc(sizeof(p_list));
	if (new != NULL)
	{
		new->name = ft_strdup(data);
		new->next = list;
	}
	return (new);
}

void	print_list(p_list *list)
{
	while (list)
	{
		ft_putendl(list->name);
		list = list->next;
	}
}

void	init_flags(t_mod *data, int i)
{
	data->l_flag = 0;
	data->r_flag = 0;
	data->a_flag = 0;
	data->br_flag = 0;
	data->t_flag = 0;
	data->n_parameters = i - 1;
}

//------------------SORT LIST------------------

p_list	*sort_list(p_list **begin_list)
{
	p_list *list;
	char	*aux;

	if (*begin_list == NULL)
		return (NULL);
	list = *begin_list;
	while (list->next)
	{
		if (ft_strcmp(list->name, list->next->name) > 0)
		{
			aux = list->name;
			list->name = list->next->name;
			list->next->name = aux;
			list = *begin_list;
		}
		else
			list = list->next;
	}
	list = *begin_list;
	return (list);
}


//--------------CHECK FILE TYPES AND ADD IT TO STRUCTURE-----------

void	check_file_type(p_list **begin_list)
{
	p_list *list;
	int r;

	list = *begin_list;
	while (list)
	{
		r = stat(list->name, &list->info);
		if (r == 0)
		{
			if (S_ISREG(list->info.st_mode))
				list->type = '-';
			else if (S_ISDIR(list->info.st_mode))
				list->type = 'd';
			else if (S_ISCHR(list->info.st_mode))
				list->type = 'c';
			else if (S_ISBLK(list->info.st_mode))
				list->type = 'b';
			else if (S_ISFIFO(list->info.st_mode))
				list->type = 'p';
			else if (S_ISLNK(list->info.st_mode))
				list->type = 'l';
			else if (S_ISSOCK(list->info.st_mode))
				list->type = 's';
		}
		else
			perror(list->name);
		list = list->next;
	}
}

//------------------COMPUTE FLAGS-----------------------

void	compute_no_flags(DIR *fd, p_list **begin_list)
{
	p_list *content;

	content = *begin_list;
	while (content)
	{
		if (content->name[0] != '.')
			ft_putendl(content->name);
		content = content->next;
	}
}

void	compute_a_flag(DIR *fd, p_list **begin_list)
{
	p_list *content;


	content = *begin_list;
	while (content)
	{
		ft_putendl(content->name);
		content = content->next;
	}
}

//-----------------COMPUTE L FLAG LISTING ALL THE DATA--------------

void	list_file_type(t_mod *data)
{
	if (S_ISREG(data->info.st_mode))
		ft_putchar('-');
	else if (S_ISDIR(data->info.st_mode))
		ft_putchar('d');
	else if (S_ISCHR(data->info.st_mode))
		ft_putchar('c');
	else if (S_ISBLK(data->info.st_mode))
		ft_putchar('b');
	else if (S_ISFIFO(data->info.st_mode))
		ft_putchar('p');
	else if (S_ISLNK(data->info.st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(data->info.st_mode))
		ft_putchar('s');
}

void	list_rights(t_mod *data)
{
	(data->info.st_mode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(data->info.st_mode & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	(data->info.st_mode & S_IXUSR) ? ft_putchar('x') : ft_putchar('-');
	(data->info.st_mode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(data->info.st_mode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	(data->info.st_mode & S_IXGRP) ? ft_putchar('x') : ft_putchar('-');
	(data->info.st_mode & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(data->info.st_mode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	(data->info.st_mode & S_IXOTH) ? ft_putchar('x') : ft_putchar('-');
}

void	list_links(t_mod *data)
{
	int len;
	int spaces;

	len = ft_nr_cifre((int)data->info.st_nlink);
	spaces = 4 - len;
	while (spaces > 0)
	{
		ft_putchar(' ');
		spaces--;
	}
	ft_putnbr(data->info.st_nlink);
}

void	list_owners(t_mod *data)
{
	data->id = getpwuid(data->info.st_uid);
	data->gr = getgrgid(data->info.st_gid);
	ft_putstr(" ");
	ft_putstr(data->id->pw_name);
	ft_putstr("  ");
	ft_putstr(data->gr->gr_name);
}

void	list_size(t_mod *data)
{
	int len;
	int spaces;

	len = data->info.st_size;
	spaces = 7 - ft_nr_cifre(len);
	while (spaces > 0)
	{
		ft_putchar(' ');
		spaces--;
	}
	ft_putnbr(data->info.st_size);
	ft_putchar(' ');
}

void	list_date(t_mod *data)
{
	char	*our_time;
	char	*new_time;
	time_t	t;

	our_time = ft_memalloc(100);
	new_time = ft_memalloc(100);
	t = time(&data->info.st_mtime);
	our_time = ctime(&t);	
	ft_memcpy(new_time, &our_time[4], 12);
	ft_putstr(new_time);
	ft_putchar(' ');
}

void	compute_l_flag(DIR *fd, p_list **begin_list, t_mod *data)
{
	p_list			*content;
	int				r;

	content = *begin_list;
	while (content)
	{
		r = stat(content->name, &data->info);
		if (r == 0)
		{
			if (content->name[0] != '.')
			{
				list_file_type(data);
				list_rights(data);
				list_links(data);
				list_owners(data);
				list_size(data);
				list_date(data);
				ft_putstr(content->name);
				ft_putchar('\n');
			}
		}
		else
			ft_putstr("error\n");
		content = content->next;
	}
}

//-------------------LIST DIRECTORY CONTENT BASED ON FLAGS--------------

int		no_flag(t_mod *data)
{
	if (data->br_flag == 0 && data->a_flag == 0 && data->r_flag == 0 && \
			data->t_flag == 0 && data->l_flag == 0)
		return (1);
	return (0);
}

void	list_content_based_on_flags(t_mod *data, DIR *fd, p_list **begin_list)
{
	if (data->a_flag == 1)
		compute_a_flag(fd, begin_list);
	if (data->l_flag == 1)
		compute_l_flag(fd, begin_list, data);
	/*if (data->R_flag == 1)
	  compute_br_flag(fd, begin_list);
	  if (data->t_flag == 1)
	  compute_t_flag(fd, begin_list);
	  */if (no_flag(data) == 1)
	compute_no_flags(fd, begin_list);
}

void	list_content(DIR *fd, t_mod *data)
{
	struct dirent *buff;
	p_list		*content;

	content = NULL;
	while ((buff = readdir(fd)) != NULL)
	{
		errno = 0;
		content = add_link(content, buff->d_name);
	}
	if (errno != 0)
		ft_putstr("error\n");
	content = sort_list(&content);
	list_content_based_on_flags(data, fd, &content);
	//free(content);
}

void	compute_dirs(p_list **begin_list, t_mod *data)
{
	p_list *list;
	DIR		*fd;
	p_list	*content;

	list = *begin_list;
	content = NULL;
	while (list)
	{
		fd = opendir(list->name);
		if (fd != NULL)
		{
			if (data->n_parameters > 1 && list->next != NULL)
			{
				ft_putstr(list->name);
				ft_putendl(":");
				list_content(fd, data);
				ft_putchar('\n');
			}
			else
				list_content(fd, data);
			closedir(fd);
		}
		list = list->next;
	}
}

int		validate_dirs(p_list **begin_list)
{
	DIR		*fd;
	p_list	*list;
	int		ok;

	list = *begin_list;
	ok = 0;
	while (list)
	{
		if (list->type == 'd')
		{
			fd = opendir(list->name);
			if (fd == NULL)
			{
				perror(list->name);
				ok = 1;
			}
			else
				closedir(fd);
		}
		list = list->next;
	}
	if (ok == 1)
		return (2);
	return (0);
}

void	set_flags(int args, char **argv, t_mod *data)
{
	int i;

	i = 1;
	while (i < args)
	{
		if (ft_strcmp(argv[i], "-l") == 0)
			data->l_flag = 1;
		else if (ft_strcmp(argv[i], "-r") == 0)
			data->r_flag = 1;
		else if (ft_strcmp(argv[i], "-a") == 0)
			data->a_flag = 1;
		else if (ft_strcmp(argv[i], "-R") == 0)
			data->br_flag = 1;
		else if (ft_strcmp(argv[i], "-t") == 0)
			data->t_flag = 1;
		else
			i = args;
		i++;
	}
}

int 	is_flag(char *str)
{
	if (ft_strcmp(str, "-l") == 0)
		return (1);
	else if (ft_strcmp(str, "-a") == 0)
		return (1);
	else if (ft_strcmp(str, "-R") == 0)
		return (1);
	else if (ft_strcmp(str, "-r") == 0)
		return (1);
	else if (ft_strcmp(str, "-t") == 0)
		return (1);
	return (0);
}

int		after_flags(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]))
			i++;
		else
			return (i);
	}
	return (i);
}

int		main(int argc, char **argv)
{
	p_list	*list;
	t_mod	data;
	int		i;

	list = NULL;
	i = after_flags(argc, argv);
	if (argc == 1 || i == argc)
		list = add_link(list, ".");
	while (i < argc)
	{
		list = add_link(list, argv[i]);
		i++;
	}
	init_flags(&data, i);
	set_flags(argc, argv, &data);
	if (list)
		list = sort_list(&list);
	//print_list(list);
	check_file_type(&list);
	if (validate_dirs(&list) == 2)
		return (2);
	compute_dirs(&list, &data);
	return (0);
}
