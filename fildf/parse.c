/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblej <mblej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:16:56 by mblej             #+#    #+#             */
/*   Updated: 2023/08/31 22:44:10 by mblej            ###   ########.fr       */
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


void	parser(char *str, t_fdf *fil)
{
	char	*l;
	int fd;

	fil->height = 0;
	fd = open(str, O_RDONLY);
	l = get_next_line(fd);
	if(!l)
		return NULL;
	fil->width = counter(l, ' ');
	while (l && ++fil->height)
	{
		l = get_next_line(fd);
		if (!l)
			break;
		if (counter(l, ' ') != fil->width || fil->height == 0)
			return ;//error
	}
	
}

