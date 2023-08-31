/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblej <mblej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:05:43 by mblej             #+#    #+#             */
/*   Updated: 2023/08/31 01:45:54 by mblej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	my_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*my_strdup(char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc((my_strlen(s1)) * sizeof(char));
	if (s2)
	{
		while (s1[i])
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = 0;
	}
	else
		return (NULL);
	return (s2);
}

char	*my_strjoin(char *str, char *buff)
{
	int		i;
	int		j;
	int		s;
	char	*tmp;

	if (!str || !buff)
		return (NULL);
	s = my_strlen(str) + my_strlen(buff);
	tmp = malloc(sizeof(char) * (s + 1));
	if (!tmp)
		return (0);
	i = 0;
	j = 0;
	while (str[i] != '\0')
		tmp[j++] = str[i++];
	i = 0;
	while (buff[i] != '\0')
		tmp[j++] = buff[i++];
	tmp[j] = 0;
	free(str);
	return (tmp);
}

char	*my_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && (*s != c))
		s++;
	if (*s == c)
		return (s);
	return (NULL);
}

char	*ft_send_join(char *s1, char *s2)
{
	if (!s1)
		s1 = my_strdup("");
	if (!s1 && !s2)
		return (NULL);
	return (my_strjoin(s1, s2));
}