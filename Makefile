
HEAD = fdf
SRC = main.c get_next_line.c get_next_line_utils.c parse.c
OBJS = $(SRC:.c=.o)
HEADERS = get_next_line.h fildf.h
FLAGS = -Wall -Wextra -Werror

all: $(HEAD)

$(HEAD): $(OBJS)
    gcc $(FLAGS) $(OBJS) -o $(HEAD)

%.o: %.c $(HEADERS)
    gcc $(FLAGS) -c $< -o $@

clean:
    rm -f $(OBJS)

fclean: clean
    rm -f $(HEAD)

re: fclean all

.PHONY: all clean fclean
