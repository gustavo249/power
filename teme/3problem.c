/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3problem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 12:15:10 by rcrisan           #+#    #+#             */
/*   Updated: 2015/11/13 14:29:01 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_mintomax(int *n, int size)
{
	int min;
	int max;
	int pos1;
	int pos2;
	int i;
	int c;

	i = 1;
	c = 0;
	pos1 = 0;
	pos2 = 0;
	max = n[0];
	min = n[0];
	while (i < size)
	{
		if (n[i] > max)
		{
			max = n[i];
			pos2 = i;
		}
		if (n[i] < min)
		{
			min = n[i];
			pos1 = i;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (n[i] == max)
			n[i] = min;
		else if (n[i] == min)
			n[i] = max;
		i++;
	}
	if ((pos2 - pos1) < 0)
	{
		while (pos1 > pos2 - 1)
			pos2++;
		printf("Numarul de elemente dintre minim si maxim este: %d\n", pos2);
	}
	else if ((pos2 - pos1) > 0)
	{
		while (pos1 < pos2 - 1)
			pos1++;
		printf("Numarul de elemente dintre minim si maxim este: %d\n", pos1);
	}
}

int main ()
{
	int i = 0;
	int n[] = { 829, 4, 12, 679, 208};
	int size = sizeof(n) / sizeof(n[i]);

	printf("Numarul de elemente: %d\n", size);
	ft_mintomax(n, size);
	
	while (i < size)
	{
		printf("%d\n", n[i]);
		i++;
	}

	return (0);
}
