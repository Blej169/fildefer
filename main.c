/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblej <mblej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:19:05 by mblej             #+#    #+#             */
/*   Updated: 2023/09/03 23:39:52 by mblej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fildf.h"

int32_t	main(int ac, char **av)
{
	t_fdf fdf;

	if(ac != 2 || !av[1])
		return(1);
	parser(av[1], &fdf);
    mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "42Balls", false);
    mlx_image_t *img = mlx_new_image(mlx, WIDTH, HEIGHT);
    mlx_image_to_window(mlx, img, 0, 0);
    ft_drew_map(&fdf, img);

    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}

