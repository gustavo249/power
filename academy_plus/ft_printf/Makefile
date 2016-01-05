# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 19:15:51 by rcrisan           #+#    #+#              #
#    Updated: 2016/01/05 13:01:27 by rcrisan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)

SRCS = srcs/*.c \
	   libft/*.c

OBJ = *.o

all: $(NAME)

$(NAME):
	@$(CC) -c $(SRCS) -I./includes
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(CC) -I./includes main.c -L. -lftprintf -o printf

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) printf

re: fclean all
