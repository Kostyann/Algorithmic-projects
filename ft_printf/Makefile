CC = gcc
FLAGS = -Wall -Wextra
LIBFLAGS = -L libft/ -lft
SOURCES = main.c resolvers.c technical.c print_funs/*.c libft/*.c
OBJECTS = *.o
NAME = libftprintf.a

all: $(SOURCES) $(NAME)

$(NAME): $(OBJECTS)
	@ar -rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

$(OBJECTS): $(SOURCES)
	@$(CC)  -c $(SOURCES) $(FLAGS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

main: re
	@rm -f $(OBJECTS)
	@$(CC) -o test $(NAME) $(LIBFLAGS)
	@./test