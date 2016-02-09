# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaha <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/22 14:15:32 by azaha             #+#    #+#              #
#    Updated: 2016/01/22 14:57:45 by azaha            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src/ft_conversions/ft_atoi.c\
	  src/ft_conversions/ft_itoa.c\
	  src/ft_conversions/ft_lltoa_base.c\
	  src/ft_conversions/ft_ulltoa_base.c\
	  src/ft_conversions/ft_tolower.c\
	  src/ft_conversions/ft_toupper.c\
	  src/ft_is/ft_abs.c\
	  src/ft_is/ft_isalnum.c\
	  src/ft_is/ft_isalpha.c\
	  src/ft_is/ft_isascii.c\
	  src/ft_is/ft_isdigit.c\
	  src/ft_is/ft_isprint.c\
	  src/ft_is/ft_nbr_len.c\
	  src/ft_lst/ft_lstadd.c\
	  src/ft_lst/ft_lstdel.c\
	  src/ft_lst/ft_lstdelone.c\
	  src/ft_lst/ft_lstiter.c\
	  src/ft_lst/ft_lstmap.c\
	  src/ft_lst/ft_lstnew.c\
	  src/ft_mem/ft_bzero.c\
	  src/ft_mem/ft_memalloc.c\
	  src/ft_mem/ft_memccpy.c\
	  src/ft_mem/ft_memchr.c\
	  src/ft_mem/ft_memcmp.c\
	  src/ft_mem/ft_memcpy.c\
	  src/ft_mem/ft_memdel.c\
	  src/ft_mem/ft_memmove.c\
	  src/ft_mem/ft_memset.c\
	  src/ft_put/ft_putchar.c\
	  src/ft_put/ft_putchar_fd.c\
	  src/ft_put/ft_putendl.c\
	  src/ft_put/ft_putendl_fd.c\
	  src/ft_put/ft_putnbr.c\
	  src/ft_put/ft_putnbr_fd.c\
	  src/ft_put/ft_putnstr.c\
	  src/ft_put/ft_putstr.c\
	  src/ft_put/ft_putstr_fd.c\
	  src/ft_str/ft_strcat.c\
	  src/ft_str/ft_strchr.c\
	  src/ft_str/ft_strclr.c\
	  src/ft_str/ft_strcmp.c\
	  src/ft_str/ft_strcpy.c\
	  src/ft_str/ft_strdel.c\
	  src/ft_str/ft_strdup.c\
	  src/ft_str/ft_strequ.c\
	  src/ft_str/ft_striter.c\
	  src/ft_str/ft_striteri.c\
	  src/ft_str/ft_strjoin.c\
	  src/ft_str/ft_strlcat.c\
	  src/ft_str/ft_strlen.c\
	  src/ft_str/ft_strmap.c\
	  src/ft_str/ft_strmapi.c\
	  src/ft_str/ft_strncat.c\
	  src/ft_str/ft_strncmp.c\
	  src/ft_str/ft_strncpy.c\
	  src/ft_str/ft_strnequ.c\
	  src/ft_str/ft_strnew.c\
	  src/ft_str/ft_strnstr.c\
	  src/ft_str/ft_strrchr.c\
	  src/ft_str/ft_strrev.c\
	  src/ft_str/ft_strsplit.c\
	  src/ft_str/ft_strstr.c\
	  src/ft_str/ft_strsub.c\
	  src/ft_str/ft_strtrim.c\
	  src/ft_printf/assign_c_type.c\
	  src/ft_printf/assign_d_type.c\
	  src/ft_printf/assign_jz.c\
	  src/ft_printf/assign_o_type.c\
	  src/ft_printf/assign_p_type.c\
	  src/ft_printf/assign_s_type.c\
	  src/ft_printf/assign_u_type.c\
	  src/ft_printf/assign_upper_c_type.c\
	  src/ft_printf/assign_upper_s_type.c\
	  src/ft_printf/assign_upper_x_type.c\
	  src/ft_printf/assign_x_type.c\
	  src/ft_printf/case_precision.c\
	  src/ft_printf/case_width.c\
	  src/ft_printf/check_flags.c\
	  src/ft_printf/check_mods.c\
	  src/ft_printf/check_numbers.c\
	  src/ft_printf/check_specifier.c\
	  src/ft_printf/element_sum.c\
	  src/ft_printf/ft_printf.c\
	  src/ft_printf/ft_putwchar.c\
	  src/ft_printf/ft_putwstr.c\
	  src/ft_printf/ft_wstrlen.c\
	  src/ft_printf/ft_wstrsub.c\
	  src/ft_printf/get_specifier.c\
	  src/ft_printf/get_wchar_len.c\
	  src/ft_printf/get_width_precision.c\
	  src/ft_printf/initialize_structures.c\
	  src/ft_printf/parse_format.c\
	  src/ft_printf/print_formated_text.c\
	  src/ft_printf/process_correct_dsc.c\
	  src/ft_printf/process_incorrect_dsc.c\
	  src/ft_printf/set_d_mod.c\
	  src/ft_printf/set_o_mod.c\
	  src/ft_printf/set_u_mod.c\
	  src/ft_printf/set_upper_d_mod.c\
	  src/ft_printf/set_upper_o_mod.c\
	  src/ft_printf/set_upper_u_mod.c\
	  src/ft_printf/set_upper_x_mod.c\
	  src/ft_printf/set_x_mod.c\
	  src/ft_printf/store_hash.c\
	  src/ft_printf/store_precision.c\
	  src/ft_printf/store_width.c\
	  src/ft_printf/wrong_specifier.c\

OBJ = ft_atoi.o\
	  ft_itoa.o\
	  ft_lltoa_base.o\
	  ft_ulltoa_base.o\
	  ft_tolower.o\
	  ft_toupper.o\
	  ft_abs.o\
	  ft_isalnum.o\
	  ft_isalpha.o\
	  ft_isascii.o\
	  ft_isdigit.o\
	  ft_isprint.o\
	  ft_nbr_len.o\
	  ft_lstadd.o\
	  ft_lstdel.o\
	  ft_lstdelone.o\
	  ft_lstiter.o\
	  ft_lstmap.o\
	  ft_lstnew.o\
	  ft_bzero.o\
	  ft_memalloc.o\
	  ft_memccpy.o\
	  ft_memchr.o\
	  ft_memcmp.o\
	  ft_memcpy.o\
	  ft_memdel.o\
	  ft_memmove.o\
	  ft_memset.o\
	  ft_putchar.o\
	  ft_putchar_fd.o\
	  ft_putendl.o\
	  ft_putendl_fd.o\
	  ft_putnbr.o\
	  ft_putnbr_fd.o\
	  ft_putnstr.o\
	  ft_putstr.o\
	  ft_putstr_fd.o\
	  ft_strcat.o\
	  ft_strchr.o\
	  ft_strclr.o\
	  ft_strcmp.o\
	  ft_strcpy.o\
	  ft_strdel.o\
	  ft_strdup.o\
	  ft_strequ.o\
	  ft_striter.o\
	  ft_striteri.o\
	  ft_strjoin.o\
	  ft_strlcat.o\
	  ft_strlen.o\
	  ft_strmap.o\
	  ft_strmapi.o\
	  ft_strncat.o\
	  ft_strncmp.o\
	  ft_strncpy.o\
	  ft_strnequ.o\
	  ft_strnew.o\
	  ft_strnstr.o\
	  ft_strrchr.o\
	  ft_strrev.o\
	  ft_strsplit.o\
	  ft_strstr.o\
	  ft_strsub.o\
	  ft_strtrim.o\
	  assign_c_type.o\
	  assign_d_type.o\
	  assign_jz.o\
	  assign_o_type.o\
	  assign_p_type.o\
	  assign_s_type.o\
	  assign_u_type.o\
	  assign_upper_c_type.o\
	  assign_upper_s_type.o\
	  assign_upper_x_type.o\
	  assign_x_type.o\
	  case_precision.o\
	  case_width.o\
	  check_flags.o\
	  check_mods.o\
	  check_numbers.o\
	  check_specifier.o\
	  element_sum.o\
	  ft_printf.o\
	  ft_putwchar.o\
	  ft_putwstr.o\
	  ft_wstrlen.o\
	  ft_wstrsub.o\
	  get_specifier.o\
	  get_wchar_len.o\
	  get_width_precision.o\
	  initialize_structures.o\
	  parse_format.o\
	  print_formated_text.o\
	  process_correct_dsc.o\
	  process_incorrect_dsc.o\
	  set_d_mod.o\
	  set_o_mod.o\
	  set_u_mod.o\
	  set_upper_d_mod.o\
	  set_upper_o_mod.o\
	  set_upper_u_mod.o\
	  set_upper_x_mod.o\
	  set_x_mod.o\
	  store_hash.o\
	  store_precision.o\
	  store_width.o\
	  wrong_specifier.o\



INCLUDES = includes/

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) -I $(INCLUDES) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f  $(NAME)

re: fclean all
