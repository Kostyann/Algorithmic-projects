CC = gcc
FLAGS = -Wall -Wextra
SOURCES = *.c
OBJECTS = $(SOURCES:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME):
	$(CC) -I includes/ -c $(SOURCES) $(FLAGS)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

