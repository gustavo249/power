/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 22:49:04 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/09 22:49:05 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_infix(t_btree *root, void (*apply)(void *))
{
	if (!root)
		return ;
	btree_apply_prefix(root->left, apply);
	(*apply)(root->item);
	btree_apply_prefix(root->right, apply);
}
