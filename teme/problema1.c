/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tema.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 11:27:48 by rcrisan           #+#    #+#             */
/*   Updated: 2015/11/11 11:46:18 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648");
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);

	}
	else
		ft_putchar(nb + '0');
}

int		is_prime(int n)
{
	int c;

	c = 2;
	while (c * c <= n)
	{
		if (n % c == 0)
			return (0);
		n = n / c;
		c++;
	}
	return (1);
}

int		invers(int n)
{
	int copie = 0;
	
	while (n != 0)
	{
		copie = copie * 10 + n % 10;
		n = n / 10;
	}
	if (is_prime(copie) == 1)
		return (1);
	return (0);
}

int main ()
{
	int start, end, i = 0, ok = 0;
	int a = 0, b = 0, c = 0;

	printf("Introdu interval de start: ");
	scanf("%d", &start);
	printf("\nIntrodu interval de end: ");
	scanf("%d", &end);
	printf("\n| Numere prime |\t\t| Primul numar par |\t\t| Numere ale caror invers este prim |\n");
	while (start <= end)
	{
		if (is_prime(start) == 1)    //verificam care sunt numere prime
			printf("\t%d\n", start);	// afisam numere prime
		if (start % 2 == 0 && ok == 0) 
		{
			printf("\t\t\t\t\t%d\n", start); // afisam primul nr par
			ok++;
		}
		if (invers(start) == 1)
			printf("\t\t\t\t\t\t\t\t\t\t%d\n", start);
	start++;
	}
	if (ok == 0)
		printf("Nu s-a gasit nici un nr par in acest interval\n");
	return (0);
}
