# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/25 13:40:57 by rcrisan           #+#    #+#              #
#    Updated: 2016/02/04 13:23:18 by rcrisan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf


SRCS =	srcs/color_map.c \
		srcs/compute_projection.c \
		srcs/draw_map.c \
		srcs/main.c \
		srcs/read_from_file.c \
		srcs/show_usage.c \

OBJ =	color_map.o \
		compute_projection.o \
		draw_map.o \
		main.o \
		read_from_file.o \
		show_usage.o \

FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)

MLX = -L includes/minilibx_macos -lmlx -framework OpenGL -framework AppKit

LIBFT = -L libft/ -lft

all: $(NAME)

$(NAME) :
	@make -C libft/
	@$(CC) $(SRCS) -c -I ./includes
	@$(CC) $(OBJ) -o $(NAME) $(MLX) $(LIBFT)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(OBJ) $(NAME)

re: fclean all
