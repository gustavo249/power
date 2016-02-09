# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/18 10:05:52 by jfazakas          #+#    #+#              #
#    Updated: 2016/01/16 23:47:30 by jfazakas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = src/main.c\
	  src/create_new_image.c\
	  src/draw_druta.c\
	  src/draw_helga.c\
	  src/draw_julia.c\
	  src/draw_kosorus.c\
	  src/draw_mandelbrot.c\
	  src/expose_hook.c\
	  src/initialize_environment.c\
	  src/key_hook.c\
	  src/motion_hook.c\
	  src/mouse_hook.c\
	  src/print_error_and_exit.c\
	  src/put_pixel.c\
	  src/print_help.c\

OBJ = main.o\
	  create_new_image.o\
	  draw_druta.o\
	  draw_helga.o\
	  draw_julia.o\
	  draw_kosorus.o\
	  draw_mandelbrot.o\
	  expose_hook.o\
	  initialize_environment.o\
	  key_hook.o\
	  motion_hook.o\
	  mouse_hook.o\
	  print_error_and_exit.o\
	  put_pixel.o\
	  print_help.o\

INC = includes/

FLAGS = -Wall -Wextra -Werror

MLX = -Lincludes/minilibx_macos -lmlx -framework OpenGL -framework AppKit

LIBFT = -L libft/ -lft

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(FLAGS) -I $(INC) -c $(SRC)
	@gcc $(OBJ) $(MLX) $(LIBFT) -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
