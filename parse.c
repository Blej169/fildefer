/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblej <mblej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:16:56 by mblej             #+#    #+#             */
/*   Updated: 2023/09/04 00:37:00 by mblej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fildf.h"


int	counter(char *str, char c)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			cmp++;
		while (str[i] != c && str[i])
			i++;
	}
	return (cmp);
}


void    init_size(int fd, t_fdf *fil)
{
    char    *l;
    
    fil->height = 0;
    l = get_next_line(fd);
    fil->width = counter(l, ' ');
    while (l && ++fil->height)
	{
		l = get_next_line(fd);
		if (!l)
			break;
		if (counter(l, ' ') != fil->width || fil->height == 0)
			return ;//error
	}
    close(fd);
}

void parser(char *str, t_fdf *fil)
{
    char *line;
    int fd;
    int y = 0, x;

    fd = open(str, O_RDONLY);
    init_size(fd, fil);
    // Allocate memory for the data 2D array
    fil->data = (int **)malloc(fil->height * sizeof(int *));
    while (y < fil->height) {
        fil->data[y] = (int *)malloc(fil->width * sizeof(int));
        y++;
    }
    // Reset the file descriptor to the beginning of the file
    fd = open(str, O_RDONLY);

    // Now, read and store the data values into fil->data
    y = 0;
    while (y < fil->height && (line = get_next_line(fd)) != NULL)
    {
        // Parse and store values in fil->data[y][x]
        char *token = strtok(line, " ");
        x = 0;
        while (token != NULL) {
            int value = atoi(token);
            fil->data[y][x] = value;

            // Calculate attitude based on z-coordinate (the value)
            if (value > fil->attitude) {
                fil->attitude = value;
            }

            token = strtok(NULL, " ");
            x++;
        }

        y++;
    }

    close(fd);
}