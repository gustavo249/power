/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:14:32 by rcrisan           #+#    #+#             */
/*   Updated: 2015/11/28 12:48:38 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		nr_cifre(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = nr_cifre(n);
	if (n > 0)
		str = (char*)malloc(sizeof(str) * i);
	else if (n == 0)
		return ("0\0");
	else
	{
		str = (char*)malloc(sizeof(str) * i + 1);
		i++;
		str[0] = '-';
	}
	str[i] = '\0';
	i--;
	while (n)
	{
		if (n % 10 < 0)
			str[i] = -(n % 10) + '0';
		else
			str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

int main (int argc, char **argv)
{
	int a;

	argc = argc - 1 + 1;
	a = atoi(argv[1]);
	printf("%s\n", ft_itoa(a));
	return (0);
}
