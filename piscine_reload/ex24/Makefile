CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJECTS = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
HEADER = includes/*.h
LIB = libft.a

all: make

make: $(OBJECTS)
	ar rc $(LIB) $(OBJECTS)
	ranlib $(LIB) 

ft_putchar.o: srcs/ft_putchar.c
	$(CC) $(FLAGS) -c srcs/ft_putchar.c

ft_putstr.o: srcs/ft_putstr.c
	$(CC) $(FLAGS) -c srcs/ft_putstr.c

ft_strcmp.o: srcs/ft_strcmp.c
	$(CC) $(FLAGS) -c srcs/ft_strcmp.c

ft_strlen.o: srcs/ft_strlen.c
	$(CC) $(FLAGS) -c srcs/ft_strlen.c

ft_swap.o: srcs/ft_swap.c
	$(CC) $(FLAGS) -c srcs/ft_swap.c

clean:
	rm -rf $(LIB)

fclean: clean
	rm -rf *.o

re: fclean make
	 