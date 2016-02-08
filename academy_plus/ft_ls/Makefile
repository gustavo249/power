# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/06 11:42:35 by rcrisan           #+#    #+#              #
#    Updated: 2016/02/08 20:16:18 by rcrisan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = srcs/main.c

OBJ = *.o

FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)

LIBFT = -L libft/ -lft

all: $(NAME)

$(NAME):
	make -C libft/
	$(CC) $(SRCS) -c -I ./includes
	$(CC) $(OBJ) -o $(NAME) $(LIBFT)

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(OBJ) $(NAME)

re: fclean all
