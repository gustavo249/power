/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problema2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 11:53:10 by rcrisan           #+#    #+#             */
/*   Updated: 2015/11/13 12:15:00 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		cmmdc(unsigned int a, unsigned int b)
{
	int r;

	r = 0;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return (a);
}

int	suma_cifre(int n)
{
	int sum;

	sum = 0;
	while (n != 0)
	{
		sum = sum + n % 10;
		n = n / 10;
	}
	return (sum);
}

int		is_prime(int n)
{
	int c;

	c = 2;
	while (c * c <= n)
	{
		if (n % c == 0)
			return (0);
		c++;
	}
	return (1);
}
int main ()
{
	unsigned int n[6]; //= { 62, 8, 41, 23, 64, 36, 12};
	int i = 0, dc = 0, rez = 0;
	int size = sizeof(n) / sizeof(n[i]);
	while (i < size)
	{
		printf("Introdu al %d -lea vectorului:\n", i);
		scanf("%d", &n[i]);
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		dc = cmmdc(n[i], n[i + 1]);
		rez = cmmdc(dc, n[i + 1]);
		i++;
	}
	printf("CMMDC al tuturor elementelor din vector este: %d\n", rez);
	i = 0;
	while (i < size - 1)
	{
		if (suma_cifre(n[i]) == suma_cifre(n[i + 1]))
			printf("\nsuma cifrelor nr | %d | este egala cu suma cifrelor nr | %d |, aceasta fiind egala cu %d\n"\
				, n[i], n[i + 1], suma_cifre(n[i]));
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		if (is_prime(n[i]) == 1 && is_prime(n[i + 1]) == 1)
			printf("\nPerechea aceasta de numere contine numere prime: |%d|, |%d|\n", n[i], n[i + 1]);
		i++;
	}
	return (0);
}
