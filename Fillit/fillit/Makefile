CC = gcc
FLAGS = -Wall -Wextra
SOURCES = main.c validation.c save_print.c magic.c ft_strnew.c
OBJECTS = main.o validation.o save_print.o magic.c ft_strnew.o
NAME = fillit

all: $(NAME)

$(NAME):
	@$(CC) -c $(SOURCES) $(FLAGS)
	@$(CC) -o $(NAME) $(OBJECTS)

clean: $(OBJECTS)
	@rm *.o

fclean: clean
	@rm -f fillit

re: fclean all


main: re
	@rm *.o
	@./fillit test.txt