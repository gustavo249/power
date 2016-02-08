/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 11:58:01 by rcrisan           #+#    #+#             */
/*   Updated: 2016/02/08 20:04:02 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "libft.h"
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>
#include <sys/xattr.h>

typedef	struct	k_list	p_list;

struct	k_list
{
	char	*name;
	char	type;
	char	*usr_rights;
	char	*grp_rights;
	char	*oth_rights;
	p_list	*next;
};

p_list  *add_link(p_list *list, char *data);
p_list  *sort_list(p_list **begin_list);
void    check_file_type(p_list **begin_list);
void    list_content(DIR *fd);
void    compute_dirs(p_list **begin_list);
int     validate_dirs(p_list **begin_list);
void    print_list(p_list *list);

#endif
