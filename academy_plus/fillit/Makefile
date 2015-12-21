# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acovaciu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 17:44:47 by acovaciu          #+#    #+#              #
#    Updated: 2015/12/18 17:44:49 by acovaciu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
	   error.c \
	   fillit.c \
	   tetrimino_new.c \
	   tetrimino_pos.c \
	   tetrimino_view.c \
	   tetrimino_collide.c\
	   tetrimino_clean.c \
	   tetrimino_count.c \
	   map_new.c \
	   map_view.c \
	   map_dup.c \
	   map_check_tetrimino.c \
	   map_print_tetrimino.c \
	   map_unprint_tetrimino.c \
	   map_reset_tetriminos.c \
	   map_solve.c \
	   recursive.c

FILLIT = fillit
NAME = $(FILLIT)
LIBFT = libft.a
HPATH = -Iincludes
GCC_FLAGS = -Wall -Werror -Wextra
CC = gcc $(GCC_FLAGS)
SRCDIR = src
RM = rm -rf
all: clean $(NAME)

$(NAME): $(LIBFT)
	@$(RM) $(FILLIT)
	@$(CC) -L. $(addprefix $(SRCDIR)/, $(SRCS)) -lft $(HPATH) -o $(NAME)

$(LIBFT):
	@make -C ./libft/
	@cp ./libft/libft.a ./

clean:
	@$(RM) $(NAME)

fclean: clean
	@$(RM) $(LIBFT)
	@make fclean -C ./libft/

re: fclean all

t1=	./fillit samples/bad1.fillit; echo '1'
t2=	./fillit samples/bad2.fillit; echo '2' 
t3=	./fillit samples/bad3.fillit; echo '3' 
t4=	./fillit samples/bad4.fillit; echo '4'
t5=	./fillit samples/bad5.fillit; echo '5'
t6=	./fillit samples/bad6.fillit ; echo '6'
t7=	./fillit samples/bad7.fillit ; echo '7'
t8=	./fillit samples/bad8.fillit ; echo '8'
t9=	./fillit samples/bad9.fillit ; echo '9'
t10= ./fillit samples/badsample.fillit ; echo '10'
t11= ./fillit samples/badsample.fillit ; echo '11'
t12= ./fillit samples/2x2.fillit ; echo '12'
t13= ./fillit samples/4L.fillit ; echo '13'
t14= ./fillit samples/9L.fillit; echo '14'
t15= ./fillit samples/bad1.fillit; echo '15'
t16= ./fillit samples/exforum.fillit; echo '16'
t17= ./fillit samples/exv3.fillit; echo '17'
t18= ./fillit samples/exv4.fillit; echo '18'
t19= ./fillit samples/exv5.fillit; echo '19'
t20= ./fillit samples/fofo.fillit; echo '20'
t21= ./fillit samples/goodsample.fillit; echo '21'
t22= ./fillit samples/long.fillit; echo '22'
t23= ./fillit samples/omg10.fillit; echo '23'
t24= ./fillit samples/omg11.fillit; echo '24'
t25= ./fillit samples/omgfofo.fillit; echo '25'
t26= ./fillit samples/omgsimple.fillit; echo '26'
t27= ./fillit samples/perfect.fillit; echo '27'
t28= ./fillit samples/sample.fillit; echo '28'
t29= ./fillit samples/sample2.fillit; echo '29'
t30= ./fillit samples/samplestaff samples/staf.fillit; echo '30'
t31= ./fillit samples/staffex.fillit samples/test.fillit; echo '31'
t32= ./fillit samples/tocheck.fillit; echo '32'

test:
	    $(t1); $(t2); $(t3); $(t4); $(t5); $(t6); $(t7); $(t8); $(t9); $(t10); $(t11);
		$(t12); $(t13); $(t14); $(t15); $(t16); $(t17); $(t18); $(t19); $(t20); $(t21);
		$(t22); $(t23); $(t24); $(t25); $(t26); $(t27); $(t28); $(t29); $(t30); $(t31);
		$(t31); $(t32)
