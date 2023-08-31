/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblej <mblej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:15:01 by mblej             #+#    #+#             */
/*   Updated: 2023/08/31 22:44:18 by mblej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILDF_H
# define FILDF_H
# include <unistd.h>
# include <stdlib.h>

typedef struct fdf
{
    char    **data;
    int width;
    int height;
} t_fdf;

#endif