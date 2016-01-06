/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 11:04:12 by rcrisan           #+#    #+#             */
/*   Updated: 2016/01/06 11:11:32 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int main (void)
{
	char *s1 = "mama are mere %-0123.ld";
	char *s2 = "0123456789 hlzj+-.#0";
	int i = 0;
	int k = 0;
	char result[100];

	while (s1[i])
	{
		printf("i = %d\n", i);
		printf("%s\n", result);
		result[k++] = *strstr(s2, (s1 + i));
		i++;
	}
	return (1);
}
