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

int	ft_atoi(const char *str)
{
	unsigned int	r;
	int				i;
	int				ng;

	i = 0;
	ng = 1;
	r = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ng *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = str[i] - '0' + (r * 10);
		i++;
	}
	return ((r * ng));
}

/* Custom strtok function*/
char*   my_strtok(char* str, const char* delimiters)
{
	static char	*lastToken;
	char	*tokenStart;

	if (str != NULL)
		lastToken = str;
	else if (lastToken == NULL)
		return NULL;
	/* Find the start of the next token (skip leading delimiters)*/
	tokenStart = lastToken;
	while (*lastToken != '\0' && my_strchr(delimiters, *lastToken) != NULL)
		lastToken++;
	/* If no token is found, return NULL*/
	if (*lastToken == '\0')
		return NULL;
	/* Find the end of the next token*/
	while (*lastToken != '\0' && my_strchr(delimiters, *lastToken) == NULL)
		lastToken++;
	/* Null-terminate the token and update lastToken*/
	if (*lastToken != '\0'){
		*lastToken = '\0';
		lastToken++;
	}
	return tokenStart;
}

// int main() {
// 		char str[] = "This is a sample string, with tokens.";
// 		const char delimiters[] = " ,."; // Delimiters: space, comma, and period

// 		// Tokenize the string and print the tokens
// 		char* token = custom_strtok(str, delimiters);
// 		while (token != NULL) {
// 				printf("Token: %s\n", token);
// 				token = custom_strtok(NULL, delimiters);
// 		}

// 		return 0;
// }

  

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
	/* Allocate memory for the data 2D array*/
	fil->data = (int **)malloc(fil->height * sizeof(int *));
	while (y < fil->height) {
		fil->data[y] = (int *)malloc(fil->width * sizeof(int));
		y++;
	}
	/* Reset the file descriptor to the beginning of the file*/
	fd = open(str, O_RDONLY);

	/* Now, read and store the data values into fil->data*/
	y = 0;
	while (y < fil->height && (line = get_next_line(fd)) != NULL)
	{
		/* Parse and store values in fil->data[y][x]*/
		char *token = my_strtok(line, " ");
		x = 0;
		while (token != NULL) {
			int value = ft_atoi(token);
			fil->data[y][x] = value;

			/* Calculate attitude based on z-coordinate (the value)*/
			if (value > fil->attitude) {
				fil->attitude = value;
			}

			token = my_strtok(NULL, " ");
			x++;
		}

		y++;
	}

	close(fd);
}