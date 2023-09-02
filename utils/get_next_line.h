/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblej <mblej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:05:29 by mblej             #+#    #+#             */
/*   Updated: 2023/09/02 23:19:37 by mblej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>


char	*get_next_line(int fd);
size_t	my_strlen(char *s);
char	*my_strjoin(char *s1, char *s2);
char	*my_strchr(char *s, int c);
char	*ft_send_join(char *s1, char *s2);
char	*my_strdup(char *s1);
#endif