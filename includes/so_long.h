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

# define WINDOW_WIDHT 	            600
# define WINDOW_HEIGHT 	            300
# define MLX_ERROR	 	            1
# define EXIT_FAILURE               -1
# define EXIT_SUCCES                0
# define EXTENSION_NAME             ".ber"
# define EXTENSION_LEN              4
# define BAD_FILE_DESCRIPTOR        -1

# define ERR_MAP_EMPTY              1
# define ERR_MSG_MAP_EMPTY          "The map is empty"

# define ERR_MALLOC                 2
# define ERR_MSG_MALLOC             "Malloc allocation error"

# define ERR_WRONG_EXTENSION        3
# define ERR_MSG_WRONG_EXTENSION    "Incorrect extension"

# define ERR_TOO_SMALL              4
# define ERR_MSG_TOO_SMALL          "The map you entered doesn't have enough line"

# define ERR_NO_WALL                5
# define ERR_MSG_NO_WALL            "The map has has a breach"

# define ERR_NOT_RECTANGLE          6
# define ERR_MSG_NOT_RECTANGLE      "The map isn't a rectangle"

# define WALL                       '1'

#include "libftprintf.h"
#include "../mlx_linux/mlx.h"
#include <stdio.h>
#include <stddef.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct      s_game
{
    char            **map;
    char            **player;
    size_t            map_line;
}                   t_game;


#endif
