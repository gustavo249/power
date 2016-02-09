/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 22:49:09 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/09 22:49:10 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_prefix(t_btree *root, void (*apply)(void *))
{
	if (!root)
		return ;
	(*apply)(root->item);
	btree_apply_prefix(root->left, apply);
	btree_apply_prefix(root->right, apply);
}
