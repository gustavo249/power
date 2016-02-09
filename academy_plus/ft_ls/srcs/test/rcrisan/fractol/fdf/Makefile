# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaha <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/10 23:30:42 by azaha             #+#    #+#              #
#    Updated: 2016/01/13 13:44:59 by azaha            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = src/allocate_points.c\
	  src/draw.c\
	  src/draw_line.c\
	  src/exit_program.c\
	  src/expose_hook.c\
	  src/fdf.c\
	  src/get_coordinates.c\
	  src/get_name.c\
	  src/get_next_line.c\
	  src/get_rows_and_columns.c\
	  src/init_env.c\
	  src/calculate_axonometry_coords.c\
	  src/get_step.c\
	  src/key_hook.c\
	  src/reset_configuration.c\
	  src/get_max_and_min_height.c\
	  src/get_color.c\
	  src/get_color_scale.c

OBJ = allocate_points.o\
	  draw.o\
	  draw_line.o\
	  exit_program.o\
	  expose_hook.o\
	  fdf.o\
	  get_coordinates.o\
	  get_name.o\
	  get_next_line.o\
	  get_rows_and_columns.o\
	  init_env.o\
	  calculate_axonometry_coords.o\
	  get_step.o\
	  key_hook.o\
	  reset_configuration.o\
	  get_max_and_min_height.o\
	  get_color.o\
	  get_color_scale.o

INCLUDES = includes/

FLAGS = -Wall -Wextra -Werror

MLX = -Lincludes/minilib_macos -lmlx -framework OpenGL -framework AppKit

LIBFT = -L libft/ -lft

all : $(NAME)

$(NAME) :
	make -C libft/
	gcc $(FLAGS) -I $(INCLUDES) -c $(SRC)
	gcc $(OBJ) $(MLX) $(LIBFT) -o $(NAME)

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all


