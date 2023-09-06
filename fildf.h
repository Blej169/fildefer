/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fildf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblej <mblej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:15:01 by mblej             #+#    #+#             */
/*   Updated: 2023/09/07 00:38:26 by mblej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILDF_H
# define FILDF_H
# include <stddef.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "MLX42.h"
# include <fcntl.h>
# include  <string.h>
# include "utils/get_next_line.h"
#include <stdint.h>
# define WIDTH 1200
# define HEIGHT 1200

typedef struct s_data
{
	int z;
	int color;
}	t_data;

typedef struct s_fdf
{
	int width;
	int height;
	int attitude;
	t_data **data;
}   t_fdf;

typedef struct s_coor{
	float x ;
	float y ;
}	t_coor;

int	counter(char *str, char c);
void	parser(char *str, t_fdf *fil);
void    init_size(int fd, t_fdf *fil);
char    *my_strtok(char* str, const char* delimiters);
int	ft_atoi(const char *str);
int custom_parse_color(char *str);
int ft_tolower(char c);
int	get_digit(char c, int base);
int ft_atoi_base(char *str, int base_digit);
void ft_drew_map(t_fdf *fdf, mlx_image_t *img);
void ft_drew_line(t_coor a,  t_coor b, mlx_image_t *img);
t_coor update_x(int i, int j, int initx, int  inity);

#endif