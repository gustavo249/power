/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 22:49:14 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/09 22:49:16 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_suffix(t_btree *root, void (*apply)(void *))
{
	if (!root)
		return ;
	btree_apply_prefix(root->left, apply);
	btree_apply_prefix(root->right, apply);
	(*apply)(root->item);
}
