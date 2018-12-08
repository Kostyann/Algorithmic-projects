CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES = *.c
OBJECTS = *.o
NAME = libft.a

all: $(NAME)

$(NAME):
	$(CC) -I . -c $(SOURCES) $(FLAGS)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

