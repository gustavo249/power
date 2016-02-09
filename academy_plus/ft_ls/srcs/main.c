/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:09:04 by rcrisan           #+#    #+#             */
/*   Updated: 2016/02/09 18:06:57 by rcrisan          ###   ########.fr       */
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

//------------------SORT LIST------------------

p_list	*sort_list(p_list **begin_list)
{
	p_list *list;
	char	*aux;

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
	struct stat info;
	int r;

	list = *begin_list;
	while (list)
	{
		r = stat(list->name, &info);
		if (r == 0)
		{
			if (S_ISREG(info.st_mode))
				list->type = '-';
			else if (S_ISDIR(info.st_mode))
				list->type = 'd';
			else if (S_ISCHR(info.st_mode))
				list->type = 'c';
			else if (S_ISBLK(info.st_mode))
				list->type = 'b';
			else if (S_ISFIFO(info.st_mode))
				list->type = 'p';
			else if (S_ISLNK(info.st_mode))
				list->type = 'l';
			else if (S_ISSOCK(info.st_mode))
				list->type = 's';
		}
		else
			perror(list->name);
		list = list->next;
	}
}

//-------------------LIST DIRECTORY CONTENT--------------

void	list_content(DIR *fd)
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
		ft_putstr("erro\n");
	content = sort_list(&content);
	while (content)
	{
		ft_putendl(content->name);
		content = content->next;
	}
	//free(content);
}

void	compute_dirs(p_list **begin_list)
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
			list_content(fd);
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

void	init_flags(t_mod *data)
{
	data->l_flag = 0;
	data->r_flag = 0;
	data->a_flag = 0;
	data->br_flag = 0;
	data->t_flag = 0;
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

int		main(int argc, char **argv)
{
	p_list	*list;
	t_mod	data;
	int		i;

	list = NULL;
	i = 1;
	if (argc == 1)
		list = add_link(list, ".");
	while (i < argc)
	{
		list = add_link(list, argv[i]);
		i++;
	}
	init_flags(&data);
	set_flags(argc, argv, &data);
	list = sort_list(&list);
	//print_list(list);
	check_file_type(&list);
	if (validate_dirs(&list) == 2)
		return (2);
	compute_dirs(&list);
	return (0);
}
