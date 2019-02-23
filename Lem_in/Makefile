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

NAME = lem-in

CC =		clang
CFLAGS =	-Wall -Wextra -Werror
LIB_DIR =	libft/
LIBC =		libft.a

SRC_DIR = srcs/
OBJ_DIR =	obj/
INCL_DIR = include/

SRC =		main.c data_read.c graph_save.c path_finder.c breadth_first.c \
			deep_first.c print_fun.c
OBJ =		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

.PHONY: all

all:		$(NAME)
	@:

$(LIBC):
	@$(MAKE) -C libft

$(NAME):	$(LIBC) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -L$(LIB_DIR) -lft $(CFLAGS)
	@echo "\033[34mCompiled successfully!\033[0m"


$(OBJ):		| $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INCL_DIR)*.h
	@echo "\033[33mCompiling $<...\033[0m"
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[32mCleaned!\033[0m"

lib-clean:
	@$(MAKE) clean -C libft

fclean:		clean
	@rm -f $(NAME)

lib-fclean:
	@$(MAKE) fclean -C libft

re:			fclean all

lib-re:
	@$(MAKE) re -C libft	
