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

int ft_tolower(char c)
{
	if(c <= 'Z' && c >= 'A')
		return (c+32);
	return c;
}

int	get_digit(char c, int base)
{
	int max_digit;

	if(base<=10)
		max_digit = base + '0';
	else
		max_digit = base - 10 + 'a';

	if (c >= '0' && c <= '9' && c < max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c < max_digit)
		return (c - 'a' + 10);
	else
		return(-1);
}

int ft_atoi_base(char *s, int base_digit) {
    int result = 0;
    int sign = 1;
    int digit;

    if (base_digit < 2 || base_digit > 16)
        return 0;
    if (*s == '-') {
        sign = -1;
        ++s;
    }
    while ((digit = get_digit(ft_tolower(*s), base_digit)) >= 0) {
		result = result * base_digit + (digit * sign);
        s++;
    }
	if (get_digit(ft_tolower(*(s)), base_digit) == -1 && *s)
		return 0;
    return result;
}

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

 //Custom strtok function
char*   my_strtok(char* str, const char* delimiters)
{
	static char	*lastToken;
	char	*tokenStart;

	if (str != NULL)
		lastToken = str;
	else if (lastToken == NULL)
		return NULL;
	 //Find the start of the next token (skip leading delimiters)
	tokenStart = lastToken;
	while (*lastToken != '\0' && my_strchr(delimiters, *lastToken) != NULL)
		lastToken++;
	// If no token is found, return NULL
	if (*lastToken == '\0')
		return NULL;
	// Find the end of the next token
	while (*lastToken != '\0' && my_strchr(delimiters, *lastToken) == NULL)
		lastToken++;
	// Null-terminate the token and update lastToken
	if (*lastToken != '\0'){
		*lastToken = '\0';
		lastToken++;
	}
	return tokenStart;
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

uint8_t custom_parse_color(char *str) {
    uint8_t color = 0;
    
    while (*str != '\0' && *str != ',') {
        str++;
    }
    if (*str == ',') {
        str++; 
        if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
            str += 2;
        }
        color = (uint8_t)ft_atoi_base(str, 16);
    }
    return color;
}


void parser(char *str, t_fdf *fil)
{
    char *line;
    int fd;
    int y , x;

    y = -1;
    fd = open(str, O_RDONLY);
    init_size(fd, fil);
    fil->data = (t_data **)malloc(fil->height * sizeof(t_data *));
    while (++y < fil->height) {
        fil->data[y] = (t_data *)malloc(fil->width * sizeof(t_data));
    }
    fd = open(str, O_RDONLY);
    y = -1;
    while (++y < fil->height && (line = get_next_line(fd)) != NULL)
    {
        char *token = my_strtok(line, " ");
        x = 0;
        while (token != NULL) {
            int z_value;
            uint8_t color = 0xFF; 
            char *comma_ptr = strchr(token, ',');
            
            if (comma_ptr != NULL) {
                z_value = ft_atoi(token);
                color = (uint8_t)custom_parse_color(token);
            }
            else
                z_value = ft_atoi(token);
            fil->data[y][x].z = z_value;
            fil->data[y][x].color = color;
            token = my_strtok(NULL, " ");
            x++;
        }
    }
    close(fd);
}
