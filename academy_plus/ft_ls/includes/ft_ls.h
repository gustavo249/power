/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 11:58:01 by rcrisan           #+#    #+#             */
/*   Updated: 2016/02/13 19:51:34 by rcrisan          ###   ########.fr       */
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
#include <errno.h>

typedef	struct	k_list	p_list;

struct	k_list
{
	char	*name;
	char	type;
	struct stat info;
	char	*usr_rights;
	char	*grp_rights;
	char	*oth_rights;
	p_list	*next;
};

typedef struct s_mod
{
	struct passwd *id;
	struct group *gr;
	struct stat info;
	int l_flag;
	int r_flag;
	int a_flag;
	int br_flag;
	int t_flag;
	int n_parameters;

}t_mod;

#endif
