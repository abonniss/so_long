/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:02:13 by abonniss          #+#    #+#             */
/*   Updated: 2022/01/21 12:32:27 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WINDOW_WIDHT 	600
# define WINDOW_HEIGHT 	300
# define MLX_ERROR	 	1
# define EXIT_FAILURE   -1
# define EXIT_SUCCES    0
# define EXTENSION_NAME ".ber"
# define EXTENSION_LEN  4
# define MAP_EMPTY          -1
# define MALLOC_ERROR       -2
# define WRONG_EXTENSION    -3
# define MAP_SMALL          -4
# define NO_WALL            -5
# define NO_RECTANGLE       -6
# define WALL               '1'


typedef struct  s_map
{
    char            **map;
    char            **player;
    int              map_line;
}                   t_map;



#include "libftprintf.h"
#include "../mlx_linux/mlx.h"
#include <stdio.h>
#include <stddef.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


#endif
