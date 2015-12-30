/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 04:49:12 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 05:18:18 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_rest(int rest)
{
	if (rest == 10)
		return ('A');
	else if (rest == 11)
		return ('B');
	else if (rest == 12)
		return ('C');
	else if (rest == 13)
		return ('D');
	else if (rest == 14)
		return ('E');
	else if (rest == 15)
		return ('F');
	else
		return (rest + 48);
}
