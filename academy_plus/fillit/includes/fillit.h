/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acovaciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:45:07 by acovaciu          #+#    #+#             */
/*   Updated: 2015/12/18 17:46:49 by acovaciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFFER 21
# define SIZE 4
# define MAX 5

typedef struct			s_tetrimino
{
	char				*cases;
	char				color;
	int					x;
	int					y;
	struct s_tetrimino	*next;
	struct s_tetrimino	*prev;
}						t_trimino;

typedef struct			s_form
{
	char				*form_basic[20];
}						t_form;

typedef struct			s_map
{
	char				**cases;
	int					target;
	int					min;
	int					count;
	t_trimino			*current;
}						t_map;

t_trimino				*fillit(char *file, char *buf, int *end,
		t_trimino *tetriminos);
t_trimino				*tetrimino_new(char *str, t_trimino *prev, int *end);
int						tetrimino_pos(t_trimino *tetrimino);
void					tetrimino_print(t_trimino *tetrimino);
void					tetrimino_view(t_trimino *tetriminos);
void					tetrimino_viewr(t_trimino *tetriminos);
void					tetrimino_check_collide(t_trimino *tetrimino);
void					tetrimino_clean(t_trimino *tetrimino);
int						tetrimino_count(t_trimino *tetriminos);
void					map_reset_tetriminos(t_map *map, t_trimino *tetriminos);
t_map					*map_new(void);
t_map					*map_dup(t_map *map);
void					map_view(t_map *map);
int						map_check_tetrimino(t_map *m, t_trimino *tet, int x,
		int y);
int						map_print_tetrimino(t_map *m, t_trimino *tet, int x,
		int y);
void					map_unprint_tetrimino(t_map *map, t_trimino *tetrimino);
t_map					*map_solve(t_map *map, t_trimino *tetrimino);
int						recursive(t_map *map, t_trimino *tetrimino);
void					error();

#endif
