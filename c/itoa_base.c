/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:53:20 by rcrisan           #+#    #+#             */
/*   Updated: 2015/11/28 14:30:26 by rcrisan          ###   ########.fr       */
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
	int i;
	char *str;

	if (n == 0)
		return ("0\0");
	i = nr_cifre(n) + 1;
	str = (char*)malloc(sizeof(str) * i);
	str[0] = '-';
	str[i] = '\0';
	i--;
	while (n)
	{
		str[i] = -(n % 10) + '0';
		i--;
		n = n / 10;
	}
	return (str);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	aux;
	i = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	while (i < j)
	{
		aux = str[i];
		str[i] = str[j];
		str[j] = aux;
		i++;
		j--;
	}
	return (str);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*q;
	int		i;

	if (value <= 0)
		return (ft_itoa(value));
	i = 0;
	str = (char*)malloc(sizeof(str) * nr_cifre(value));
	q = "0123456789abcdef";
	while (value)
	{
		str[i] = q[value % base];
		value = value / base;
		i++;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

int main (int argc, char **argv)
{
	int a;
	int base;

	argc = argc + 1 - 1;
	a = atoi(argv[1]);
	base = atoi(argv[2]);
	printf("%s\n", ft_itoa_base(a, base));
	return (0);
}
