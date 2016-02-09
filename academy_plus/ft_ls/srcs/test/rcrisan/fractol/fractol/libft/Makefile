# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfazakas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/24 08:38:52 by jfazakas          #+#    #+#              #
#    Updated: 2016/01/10 01:21:13 by jfazakas         ###   ########.fr        #
#    Updated: 2015/12/16 18:43:36 by jfazakas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CHAR = char/ft_isalpha.c\
	   char/ft_isdigit.c\
	   char/ft_isalnum.c\
	   char/ft_isascii.c\
	   char/ft_isprint.c\
	   char/ft_islower.c\
	   char/ft_isupper.c\
	   char/ft_isspace.c\
	   char/ft_isblank.c\
	   char/ft_isanyof.c\
	   char/ft_toupper.c\
	   char/ft_tolower.c\

MEMORY = memory/ft_memset.c\
		 memory/ft_bzero.c\
		 memory/ft_memcpy.c\
		 memory/ft_memccpy.c\
		 memory/ft_memmove.c\
		 memory/ft_memchr.c\
		 memory/ft_memcmp.c\
		 memory/ft_memalloc.c\
		 memory/ft_memdel.c\

CONVERSION = conversion/ft_itoa.c\
			 conversion/ft_ltoa.c\
			 conversion/ft_lltoa.c\
			 conversion/ft_uitoa.c\
			 conversion/ft_ultoa.c\
			 conversion/ft_ulltoa.c\
			 conversion/ft_utobin.c\
			 conversion/ft_utooctal.c\
			 conversion/ft_utohexa.c\
			 conversion/ft_atoi.c\
			 conversion/ft_dtoa.c\

LIST = list/ft_lstnew.c\
	   list/ft_lstnewnode.c\
	   list/ft_lstdelone.c\
	   list/ft_lstdel.c\
	   list/ft_lstadd.c\
	   list/ft_lstiter.c\
	   list/ft_lstmap.c\
	   list/ft_lstsize.c\
	   list/ft_lstaddend.c\
	   list/ft_lstsort.c\
	   list/ft_lstinsert.c\
	   list/ft_lstswap.c\

TYPE_LIST = type_list/ft_slistnew.c\
			type_list/ft_slistadd.c\
			type_list/ft_slistsize.c\
			type_list/ft_slistswap.c\
			type_list/ft_nlistnew.c\
			type_list/ft_nlistadd.c\
			type_list/ft_uclistnew.c\
			type_list/ft_uclistadd.c\
			type_list/ft_plistnew.c\
			type_list/ft_plistadd.c\
			type_list/ft_plistdel.c\

NUMBER = number/ft_swap.c\
		 number/ft_numlen.c\
		 number/ft_unumlen.c\
		 number/ft_abs.c\

PRINT = print/ft_putchar.c\
		print/ft_putstr.c\
		print/ft_putendl.c\
		print/ft_putnbr.c\
		print/ft_putchar_fd.c\
		print/ft_putstr_fd.c\
		print/ft_putendl_fd.c\
		print/ft_putnbr_fd.c\
		print/ft_putnuml.c\
		print/ft_putwchar.c\
		print/ft_putwstr.c\

STRING = string/ft_strlen.c\
		 string/ft_strdup.c\
		 string/ft_strcpy.c\
		 string/ft_strncpy.c\
		 string/ft_strcat.c\
		 string/ft_strncat.c\
		 string/ft_strlcat.c\
		 string/ft_strchr.c\
		 string/ft_strrchr.c\
		 string/ft_strstr.c\
		 string/ft_strnstr.c\
		 string/ft_strcmp.c\
		 string/ft_strncmp.c\
		 string/ft_strnew.c\
		 string/ft_strdel.c\
		 string/ft_strclr.c\
		 string/ft_striter.c\
		 string/ft_striteri.c\
		 string/ft_strmap.c\
		 string/ft_strmapi.c\
		 string/ft_strequ.c\
		 string/ft_strnequ.c\
		 string/ft_strsub.c\
		 string/ft_strjoin.c\
		 string/ft_strtrim.c\
		 string/ft_strsplit.c\
		 string/ft_strrev.c\
		 string/ft_strupcase.c\
		 string/ft_strlowcase.c\
		 string/ft_strcapitalize.c\
		 string/ft_strlcpy.c\

WIDE_STRING = wide_string/ft_wide_char_size.c\
			  wide_string/ft_wide_string_length.c\
			  wide_string/ft_wide_string_size.c\
			  wide_string/ft_wide_string_new.c\
			  wide_string/ft_wide_string_dup.c\

BINARY_TREE = binary_tree/btree_apply_prefix.c\
			  binary_tree/btree_apply_infix.c\
			  binary_tree/btree_apply_suffix.c\
			  binary_tree/btree_insert_data.c\
			  binary_tree/btree_search_item.c\
			  binary_tree/btree_level_count.c\

GET_NEXT_LINE = get_next_line/get_next_line.c\

SRC = $(MEMORY)\
	  $(CONVERSION)\
	  $(CHAR)\
	  $(STRING)\
	  $(LIST)\
	  $(TYPE_LIST)\
	  $(PRINT)\
	  $(MEMORY)\
	  $(NUMBER)\
	  $(WIDE_STRING)\
	  $(BINARY_TREE)\
	  $(GET_NEXT_LINE)\

OBJ = ft_memset.o\
	  ft_bzero.o\
	  ft_memcpy.o\
	  ft_memccpy.o\
	  ft_memmove.o\
	  ft_memchr.o\
	  ft_memcmp.o\
	  ft_strlen.o\
	  ft_strdup.o\
	  ft_strcpy.o\
	  ft_strncpy.o\
	  ft_strcat.o\
	  ft_strncat.o\
	  ft_strlcat.o\
	  ft_strchr.o\
	  ft_strrchr.o\
	  ft_strstr.o\
	  ft_strnstr.o\
	  ft_strcmp.o\
	  ft_strncmp.o\
	  ft_atoi.o\
	  ft_isalpha.o\
	  ft_isdigit.o\
	  ft_isalnum.o\
	  ft_isascii.o\
	  ft_isprint.o\
	  ft_toupper.o\
	  ft_tolower.o\
	  ft_memalloc.o\
	  ft_memdel.o\
	  ft_strnew.o\
	  ft_strdel.o\
	  ft_strclr.o\
	  ft_striter.o\
	  ft_striteri.o\
	  ft_strmap.o\
	  ft_strmapi.o\
	  ft_strequ.o\
	  ft_strnequ.o\
	  ft_strsub.o\
	  ft_strjoin.o\
	  ft_strtrim.o\
	  ft_strsplit.o\
	  ft_itoa.o\
	  ft_putchar.o\
	  ft_putstr.o\
	  ft_putendl.o\
	  ft_putnbr.o\
	  ft_putchar_fd.o\
	  ft_putstr_fd.o\
	  ft_putendl_fd.o\
	  ft_putnbr_fd.o\
	  ft_putwstr.o\
	  ft_lstnew.o\
	  ft_lstnewnode.o\
	  ft_lstdelone.o\
	  ft_lstdel.o\
	  ft_lstadd.o\
	  ft_lstiter.o\
	  ft_lstmap.o\
	  ft_lstsize.o\
	  ft_lstaddend.o\
	  ft_lstsort.o\
	  ft_lstinsert.o\
	  ft_lstswap.o\
	  ft_islower.o\
	  ft_isupper.o\
	  ft_isspace.o\
	  ft_isblank.o\
	  ft_isanyof.o\
	  ft_swap.o\
	  ft_strrev.o\
	  ft_strupcase.o\
	  ft_strlowcase.o\
	  ft_strcapitalize.o\
	  ft_strlcpy.o\
	  ft_putnuml.o\
	  ft_utooctal.o\
	  ft_utobin.o\
	  ft_utohexa.o\
	  ft_slistnew.o\
	  ft_slistadd.o\
	  ft_numlen.o\
	  ft_slistsize.o\
	  ft_slistswap.o\
	  ft_abs.o\
	  ft_ltoa.o\
	  ft_uitoa.o\
	  ft_putwchar.o\
	  ft_lltoa.o\
	  ft_ulltoa.o\
	  ft_ultoa.o\
	  ft_dtoa.o\
	  ft_unumlen.o\
	  ft_wide_char_size.o\
	  ft_wide_string_length.o\
	  ft_wide_string_size.o\
	  ft_wide_string_new.o\
	  ft_wide_string_dup.o\
	  get_next_line.o\
	  ft_nlistnew.o\
	  ft_nlistadd.o\
	  ft_uclistnew.o\
	  ft_uclistadd.o\
	  ft_plistnew.o\
	  ft_plistadd.o\
	  ft_plistdel.o\
	  btree_apply_prefix.o\
	  btree_apply_infix.o\
	  btree_apply_suffix.o\
	  btree_insert_data.o\
	  btree_search_item.o\
	  btree_level_count.o\

FLAGS = -Wall -Wextra -Werror

INC = includes/

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC) -I $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
