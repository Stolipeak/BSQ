# Makefile simple pour BSQ
NAME = bsq
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = src/main.c src/process.c src/parse.c src/solve.c src/utils.c
OBJ = $(SRC:.c=.o)
HEADER = src/bsq.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
