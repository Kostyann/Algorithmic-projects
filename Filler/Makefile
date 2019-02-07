# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yserhii <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 16:30:46 by yserhii          #+#    #+#              #
#    Updated: 2018/12/20 16:30:48 by yserhii         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = yserhii.filler

CC =		gcc
FLAGS =		-Wall -Wextra
LIB_DIR =	libft/
LIBC =		libft.a

OBJ_DIR =	obj/

SRC =		filler.c tricks.c
OBJ =		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all:		$(LIBC) $(NAME)

$(LIBC):
	@$(MAKE) -C libft

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -L$(LIB_DIR) -lft $(FLAGS)


$(OBJ):		| $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o:	%.c
	@$(CC) -c $< -o $@ $(FLAGS)


clean:
	@rm -rf $(OBJ_DIR)
fclean:		clean
	@rm -f $(NAME)
re:			fclean all

main: all
	@./$(NAME)

s00: all
	@cd resources && ./filler_vm -p1 ../yserhii.filler -f maps/map00

s01: all
	@cd resources && ./filler_vm -p1 ../yserhii.filler -f maps/map01

s02: all
	@cd resources && ./filler_vm -p1 ../yserhii.filler -f maps/map02

s03: all
	@cd resources && ./filler_vm -p1 ../yserhii.filler -f maps/map03

m00p1: all
	@cd resources && ./filler_vm -p1 ../yserhii.filler \
    	 -p2 players/carli.filler -f maps/map00

m01p1: all
	@cd resources && ./filler_vm -p1 ../yserhii.filler \
    	 -p2 players/carli.filler -f maps/map01

m02p1: all
	@cd resources && ./filler_vm -p1 ../yserhii.filler \
    	 -p2 players/carli.filler -f maps/map02

m03p1: all
	@cd resources && ./filler_vm -p1 ../yserhii.filler \
	 -p2 players/carli.filler -f maps/map03

m00p2: all
	@cd resources && ./filler_vm -p1 players/carli.filler \
    -p2 ../yserhii.filler -f maps/map00

m01p2: all
	@cd resources && ./filler_vm -p1 players/carli.filler \
    -p2 ../yserhii.filler -f maps/map01

m02p2: all
	@cd resources && ./filler_vm -p1 players/carli.filler \
    -p2 ../yserhii.filler -f maps/map02

m03p2: all
	@cd resources && ./filler_vm -p1 players/carli.filler \
    -p2 ../yserhii.filler -f maps/map03