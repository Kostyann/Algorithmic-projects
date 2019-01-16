# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 16:30:46 by kmerkulo          #+#    #+#              #
#    Updated: 2018/12/20 16:30:48 by kmerkulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC =		clang
CFLAGS =	-Wall -Wextra
LIB_DIR =	libft/
LIBC =		libft.a
MLX_DIR =	-I /usr/local/include
FRAMEWORK = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

OBJ_DIR =	obj/

SRC =		main.c draws.c technical.c
OBJ =		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

.PHONY: all

all:		$(LIBC) $(NAME)
	@:

$(LIBC):
	@$(MAKE) -C libft

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(MLX_DIR) $(FRAMEWORK) -L$(LIB_DIR) -lft $(CFLAGS)


$(OBJ):		| $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o:	%.c
	@$(CC) -c $< -o $@ $(CFLAGS)


clean:
	@rm -rf $(OBJ_DIR)
fclean:		clean
	@rm -f $(NAME)
re:			fclean all

42: all
	@./$(NAME) test_maps/42.fdf

pyramide: all
	@./$(NAME) test_maps/pyramide.fdf

mars: all
	@./$(NAME) test_maps/mars.fdf
