# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 19:15:51 by rcrisan           #+#    #+#              #
#    Updated: 2016/01/22 16:31:20 by rcrisan          ###   ########.fr        #
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
	@$(CC) -c $(SRCS) -I./includes -I./libft/includes
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) printf

re: fclean all
