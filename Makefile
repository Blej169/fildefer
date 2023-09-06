NAME = fdf
CC = gcc
SRC = main.c utils/get_next_line.c utils/get_next_line_utils.c parse.c drawer.c
OBJS = $(SRC:.c=.o)
HEADERS = fildf.h
CFLAGS := -Wall -Wextra -Werror
LIBS := MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
