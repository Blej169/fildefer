/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fildf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblej <mblej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:15:01 by mblej             #+#    #+#             */
/*   Updated: 2023/09/02 23:22:30 by mblej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILDF_H
# define FILDF_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include "utils/get_next_line.h"

typedef struct fdf
{
    int width;
    int height;
} t_fdf;

int	counter(char *str, char c);
void	parser(char *str, t_fdf *fil);
#endif