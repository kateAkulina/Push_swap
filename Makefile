# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 15:52:49 by lcutjack          #+#    #+#              #
#    Updated: 2019/03/12 18:23:38 by lcutjack         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = coms.c show.c kinda_sort.c fill_stack.c middle_sort.c basics.c
SRCM = push_swap.c checker.c
OBJ = $(SRC:.c=.o)
OBJM = $(SRCM:.c=.o)
INC = push_swap.h

all: game

game: $(OBJ) $(OBJM)
	@make -C libft/
	@gcc $(OBJ) checker.o -I $(INC) -L. libft/libft.a -o checker
	@gcc $(OBJ) push_swap.o -I $(INC) -L. libft/libft.a -o push_swap

clean:
	@make clean -C libft/
	@rm -rf *.o

fclean: clean
	@rm -rf ./checker ./push_swap

re: fclean all