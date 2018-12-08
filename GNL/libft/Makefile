CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES = *.c
OBJECTS = *.o
HEADER = includes/
NAME = libft.a

all: $(NAME)

$(NAME):
	$(CC) -I $(HEADER) -c $(SOURCES) $(FLAGS)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

