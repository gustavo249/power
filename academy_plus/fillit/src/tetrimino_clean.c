/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:18:45 by rcrisan           #+#    #+#             */
/*   Updated: 2015/12/23 14:44:30 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	who_are_you(t_trimino *lst, t_form *form)
{
	char		*str;
	int			x;

	x = 0;
	while (lst)
	{
		while (x < 19)
		{
			str = ft_strstr(lst->cases, form->form_basic[x]);
			if (str != NULL)
			{
				ft_strclr(lst->cases);
				lst->cases = ft_strcpy(lst->cases, form->form_basic[x]);
				break ;
			}
			x++;
		}
		if (lst->next == NULL)
			return ;
		if (lst->next != NULL)
			lst = lst->next;
		x = 0;
	}
}

static void	create_form(t_form *form)
{
	form->form_basic[0] = "####";
	form->form_basic[1] = "#...#...#...#";
	form->form_basic[2] = "#...#...##";
	form->form_basic[3] = "###.#";
	form->form_basic[4] = "##...#...#";
	form->form_basic[5] = ".#...#..##";
	form->form_basic[6] = "#...###";
	form->form_basic[7] = "..#.###";
	form->form_basic[8] = "##..#...#";
	form->form_basic[9] = "###...#";
	form->form_basic[10] = "##..##";
	form->form_basic[11] = ".#..###";
	form->form_basic[12] = "#...##..#";
	form->form_basic[13] = "###..#";
	form->form_basic[14] = ".#..##...#";
	form->form_basic[15] = "##...##";
	form->form_basic[16] = "#...##...#";
	form->form_basic[17] = ".##.##";
	form->form_basic[18] = ".#..##..#";
}

void		tetrimino_clean(t_trimino *tetriminos)
{
	t_form	*form;

	form = malloc(sizeof(t_form));
	create_form(form);
	who_are_you(tetriminos, form);
}
