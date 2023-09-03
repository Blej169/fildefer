NAME = fdf
CC = gcc
SRC = main.c utils/get_next_line.c utils/get_next_line_utils.c parse.c
OBJS = $(SRC:.c=.o)
HEADERS = fildf.h
CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
