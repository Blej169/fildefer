# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblej <mblej@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 23:21:16 by mblej             #+#    #+#              #
#    Updated: 2023/08/31 01:28:42 by mblej            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD = fdf
SRC = fdf/parse.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c

FLAGS = -Wall -Wextra -Werror
HEADERS = ../get_next_line/get_next_line.h fdf/fdf.h
OBJ = $(SRC: .c=.o)
all : $(HEAD)

$(HEAD): $(OBJ)
	gcc	$(FLAGS) $(OBJ) -o $(HEAD)

%.o: %.c $(HEADERS)
	gcc $(FLAGS) -c $< -o $@

clean:
rm -f $(OBJS)

fclean: clean