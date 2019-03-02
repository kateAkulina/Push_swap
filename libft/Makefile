# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:27:08 by lcutjack          #+#    #+#              #
#    Updated: 2019/03/01 18:29:32 by lcutjack         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	  ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_atoi.c \
	  ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_tolower.c ft_isalpha.c \
	  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	  ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	  ft_lstmap.c ft_lstadd_into.c ft_lstsize.c ft_replace.c ft_rejoin.c \
	  ft_lstcpy.c ft_del.c ft_itoa_base.c ft_itoa_base_pos.c ft_str_tup.c \
	  get_next_line.c ft_is_ok.c
SRCPF = ft_basic.c ft_printf.c ft_t_csp.c ft_t_di.c ft_t_f.c ft_t_oux.c \
	what_type.c
INC = libft.h get_next_line.h ft_printf.h
OBJ = $(SRC:.c=.o)
OBJPF = $(SRCPF:.c=.o)

$(NAME): $(OBJ) $(OBJPF)
	@gcc $(FLAGS) -c $(SRC) $(SRCPRINTF) -I $(INC)
	@ar rc $(NAME) $(OBJ) $(OBJPF)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
