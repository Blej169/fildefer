# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblej <mblej@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 23:21:16 by mblej             #+#    #+#              #
#    Updated: 2023/08/31 22:49:09 by mblej            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD = fdf
SRC = fildf/parse.c fildf/main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
FLAGS = -Wall -Wextra -Werror
HEADERS = get_next_line/get_next_line.h fildf/fildf.h
OBJS = $(SRC:.c=.o)

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

.PHONY: all clean fclean re
