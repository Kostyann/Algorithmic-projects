CC = gcc
FLAGS = -Wall -Wextra
SOURCES = main.c get_next_line.c

all:
	$(CC) -o test $(SOURCES) -L libft/ -lft $(FLAGS)

clean:
	/bin/rm -f a.out

fclean: clean
	

re: fclean all


main: re
	./test
