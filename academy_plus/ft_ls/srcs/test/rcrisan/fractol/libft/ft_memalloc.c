/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 15:53:12 by azaha             #+#    #+#             */
/*   Updated: 2015/11/09 18:22:20 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (!(ptr = (void*)malloc(sizeof(*ptr) * size)) || (size == 0))
		return (NULL);
	ptr = ft_memset(ptr, '\0', size);
	return (ptr);
}
