# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/19 12:56:23 by kmerkulo          #+#    #+#              #
#    Updated: 2018/12/19 12:56:27 by kmerkulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs/
PRINTF_DIR = srcs/ft_printf/
PRINTFUNS_DIR = srcs/ft_printf/print_funs/

OBJ_DIR	= obj/

SRC =		resolvers.c technical.c print_helpers.c ft_printf.c \
            print_b.c print_c.c print_d.c print_else.c print_f.c print_o.c \
            print_p.c print_s.c print_u.c print_x.c \
            ft_atoi.c ft_bzero.c ft_isalnum.c \
            ft_isalpha.c ft_isascii.c ft_isblank.c ft_isdigit.c ft_islower.c \
            ft_isnumber.c ft_isprint.c ft_isupper.c ft_itoa.c ft_lstadd.c \
            ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
            ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
            ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
            ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
            ft_putnbr_fd.c ft_putnstr.c ft_putstr.c ft_putstr_fd.c ft_strcat.c \
            ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
            ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
            ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmap.c ft_strmapi.c \
            ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c \
            ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
            ft_strsub.c ft_strtrim.c ft_strtrimc.c ft_tolower.c ft_toupper.c \
            get_next_line.c

OBJ = 	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: 		$(NAME)

$(NAME): 	$(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ):		| $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -c $< -o $@ $(FLAGS)

$(OBJ_DIR)%.o: $(PRINTF_DIR)%.c
	@$(CC) -c $< -o $@ $(FLAGS)

$(OBJ_DIR)%.o: $(PRINTFUNS_DIR)%.c
	@$(CC) -c $< -o $@ $(FLAGS)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
