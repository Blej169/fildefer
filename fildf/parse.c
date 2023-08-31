/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblej <mblej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:16:56 by mblej             #+#    #+#             */
/*   Updated: 2023/08/31 01:51:25 by mblej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


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


void	parser(int fd, t_fdf *fil)
{
	char	*l;

	fil->height = 0;
	l = get_next_line(fd);
	if(!l)
		return NULL;
	fil->width = counter(l);
	while (l)
	{
		l = get_next_line(fd);
	}
	
}

