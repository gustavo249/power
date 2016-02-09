/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazakas <jfazakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:42:59 by jfazakas          #+#    #+#             */
/*   Updated: 2016/01/17 00:10:58 by jfazakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"

# define WINDOW_WIDTH 1400
# define WINDOW_HEIGHT 1000
# define MAX_STEPS 256
# define POINTERMOTIONMASK (1L<<6)
# define MOTIONNOTIFY 6

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*string;
	char		type;
	char		color;
	int			step;
	float		zoom;
	float		origin_x;
	float		origin_y;
	float		julia_x;
	float		julia_y;
	float		move_x;
	float		move_y;
}				t_env;

int				expose_hook(t_env *e);
void			put_pixel(char *string, char color, char rgb);
void			initialize_environment(t_env *e, char *type);
void			create_new_image(t_env *e);
int				key_hook(int keycode, t_env *e);
void			print_error_and_exit(void);
void			draw_julia(t_env *e);
void			draw_mandelbrot(t_env *e);
void			draw_kosorus(t_env *e);
void			draw_druta(t_env *e);
void			draw_helga(t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
int				motion_hook(int x, int y, t_env *e);
void			print_help(t_env *e);

#endif
