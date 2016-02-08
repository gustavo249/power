/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:09:04 by rcrisan           #+#    #+#             */
/*   Updated: 2016/02/08 18:08:55 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

p_list	*add_link(p_list *list, char *data)
{
	p_list *new;

	new = malloc(sizeof(t_list));
	if (new != NULL)
	{
		new->name = data;
		new->next = list;
	}
	return (new);
}

void	print_list(p_list *list)
{
	while (list != NULL)
	{
		ft_putstr(list->name);
		ft_putchar('\n');
		list = list->next;
	}
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
			if (S_ISREG(info->st_mode))
				list->type = '-';
		}
	}
}

int		validate_arguments(p_list **begin_list)
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

int		main(int argc, char **argv)
{
	p_list	*list;
	int		i;

	list = NULL;
	i = argc - 1;
	while (i > 0)
	{
		list = add_link(list, argv[i]);
		i--;
	}
	//print_list(list);
	check_file_type(&list);
	if (validate_arguments(&list) == 2)
		return (2);
	return (0);
}
