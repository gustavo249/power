/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:18:01 by rcrisan           #+#    #+#             */
/*   Updated: 2015/11/28 13:53:11 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_nrcifre(int n)
{
	int i;

	i = 0;
	while(n)
	{
		n /= 10;		// n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_strrev(char *str)
{
	int i;
	int j;
	char aux;

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

void	print_hex(int n)
{
	int		i;
	char	*str;
	char	*q;
	str = (char*)malloc(sizeof(str) * ft_nrcifre(n));
	q = "0123456789abcdef";
	i = 0;
	while (n)
	{
		str[i] = q[n % 16];
		i++;
		n /= 16;
	}
	str[i] = '\0';
	printf("%s\n", ft_strrev(str));
}

int main (int argc, char **argv)
{
	int a;

	argc = argc + 1 - 1;
	a = atoi(argv[1]);
	print_hex(a);
	return (0);
}
