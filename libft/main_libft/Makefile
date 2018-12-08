CC = gcc
FLAGS = -Wall -Wextra
SOURCES = srcs/*.c
OBJECTS = *.o
NAME = libft.a
all: $(NAME)

$(NAME):
	$(CC) -I . -c $(SOURCES) $(FLAGS)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	/bin/rm -f *.o

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

main: re
	gcc -L. -lft main.c
	./a.out

