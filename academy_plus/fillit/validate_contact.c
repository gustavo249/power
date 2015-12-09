/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_contact.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:48:36 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/09 17:26:43 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*g_vi;
int		*g_vj;
int g_dj[4] = { 0, -1, 0, 1 };
int g_di[4] = { -1, 0, 1, 0 };

void	create_vectors(void)
{
	int i;

	i = 0;
	g_vi = (int*)malloc(sizeof(int) * 10);
	g_vj = (int*)malloc(sizeof(int) * 10);
}

void	recursive(char **matrix, int len)
{
	int k;
	int i_new;
	int	j_new;

	if (len == 0)
		return ;
	k = 0;
	while (k <= 3)
	{
		i_new = g_vi[0] + g_di[k];
		j_new = g_vj[0] + g_dj[k];
		if (i_new >= 0 && i_new < 4 && j_new >= 0 && j_new < 4)
			if (matrix[i_new][j_new] == '#')
			{
				g_vi[len] = i_new;
				g_vj[len] = j_new;
				len++;
			}
		k++;
	}
	matrix[g_vi[0]][g_vj[0]] = 'z';
	g_vi++;
	g_vj++;
	recursive(matrix, len - 1);
}

int		ft_valid_self(char **matrix)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			if (matrix[i][j] == '#')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_init(int *i, int *j, int *ok)
{
	*i = 0;
	*j = 0;
	*ok = 0;
}

int		validate_contacts(char **matrix)
{
	int i;
	int j;
	int ok;

	ft_init(&i, &j, &ok);
	create_vectors();
	while (i < 4 && ok == 0)
	{
		j = 0;
		while (j < 4 && ok == 0)
		{
			if (matrix[i][j] == '#')
			{
				g_vi[0] = i;
				g_vj[0] = j;
				ok = 1;
				recursive(matrix, 1);
			}
			j++;
		}
		i++;
	}
	return (ft_valid_self(matrix));
}
