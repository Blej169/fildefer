/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fildf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblej <mblej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:15:01 by mblej             #+#    #+#             */
/*   Updated: 2023/09/04 00:51:19 by mblej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILDF_H
# define FILDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include  <string.h>
# include "utils/get_next_line.h"

typedef struct s_fdf
{
	int width;
	int height;
	int attitude;
	int **data;
}   t_fdf;

int	counter(char *str, char c);
void	parser(char *str, t_fdf *fil);
void    init_size(int fd, t_fdf *fil);
char    *my_strtok(char* str, const char* delimiters);
int	ft_atoi(const char *str);

#endif