/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocota <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 04:44:51 by ocota             #+#    #+#             */
/*   Updated: 2015/11/14 04:46:09 by ocota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chartoint(char c)
{
	if (c == 'A' || c == 'a')
		return (10);
	else if (c == 'B' || c == 'b')
		return (11);
	else if (c == 'C' || c == 'c')
		return (12);
	else if (c == 'D' || c == 'd')
		return (13);
	else if (c == 'E' || c == 'e')
		return (14);
	else if (c == 'F' || c == 'f')
		return (15);
	else
		return (c - 48);
}
