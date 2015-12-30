/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 03:35:13 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 03:37:06 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*f)(void *, size_t))
{
	if ((*alst)->next)
		ft_lstdel(&((*alst)->next), f);
	(*f)(&((*alst)->content), (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
