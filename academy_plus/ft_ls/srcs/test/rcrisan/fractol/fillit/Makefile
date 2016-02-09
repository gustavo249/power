# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vplaton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/16 11:07:24 by vplaton           #+#    #+#              #
#    Updated: 2016/01/07 12:42:22 by azaha            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = src/back.c \
	src/back_utils.c \
	src/check_fd.c \
	src/check_line.c \
	src/check_newline.c \
	src/directions_back.c \
	src/exit_program.c \
	src/get_shapes.c \
	src/init_elem.c \
	src/main.c \
	src/process_tetriminos.c \
	src/save_line.c \
	src/spaces.c \
	src/utils.c
INCLUDES = includes/
OBJ = back.o \
	back_utils.o \
	check_fd.o \
	check_line.o \
	check_newline.o \
	directions_back.o \
	exit_program.o \
	get_shapes.o \
	init_elem.o \
	main.o \
	process_tetriminos.o \
	save_line.o \
	spaces.o \
	utils.o

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $(SRCS)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
