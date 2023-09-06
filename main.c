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

int	main(int ac, char **av)
{
	t_fdf fdf;
	int i = 0;

	if(ac != 2 || !av[1])
		return(1);
	parser(av[1], &fdf);
	while (i < fdf.height)
	{
		int j =0;
		while (j < fdf.width)
		{
			printf("%d.%d  ", fdf.data[i][j].z, fdf.data[i][j].color);
			j++;
		}
		printf("\n");
		i++;
	}
	
	return 0;
}