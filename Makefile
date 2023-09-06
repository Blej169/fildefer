NAME = fdf
CC = gcc -O3 
SRC = main.c utils/get_next_line.c utils/get_next_line_utils.c parse.c drawer.c
OBJS = $(SRC:.c=.o)
HEADERS = fildf.h
CFLAGS := -Wall -Wextra -Werror
LIB_PATH =  -Iinclude -lglfw -L"/goinfre/mblej/homebrew/Cellar/glfw/3.3.8/lib" -lm
#LLIBS := libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
LIBS := libmlx42.a

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LIB_PATH) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
