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
# define ERR_MSG_MAP_EMPTY          "The MAP is empty"

# define ERR_MALLOC                 2
# define ERR_MSG_MALLOC             "Malloc allocation error"

# define ERR_WRONG_EXTENSION        3
# define ERR_MSG_WRONG_EXTENSION    "Incorrect extension"

# define ERR_TOO_SMALL              4
# define ERR_MSG_TOO_SMALL          "The MAP you entered doesn't have enough line"

# define ERR_NO_WALL                5
# define ERR_MSG_NO_WALL            "The MAP has has a breach"

# define ERR_NOT_RECTANGLE          6
# define ERR_MSG_NOT_RECTANGLE      "The MAP isn't a rectangle"

# define ERR_BAD_FD                 7
# define ERR_MSG_BAD_FD             "The FD is not valid"

# define ERR_WRG_COMP               8
# define ERR_MSG_WRG_COMP           "The composition of the MAP is not correct"

# define ERR_TOO_MANY_PLAYER        9
# define ERR_MSG_TOO_MANY_PLAYER    "There is no OR too many PLAYER on the MAP"

# define ERR_TOO_MANY_EXIT          10
# define ERR_MSG_TOO_MANY_EXIT      "There is no OR too many EXIT on the MAP"

# define ERR_NO_COLLECTIBLE         11
# define ERR_MSG_NO_COLLECTIBLE     "There is no COLLECTIBLE on the MAP"

# define WALL                       '1'
# define EMPTY                      '0'
# define PLAYER                     'P'
# define COLLECTIBLE                'C'
# define EXIT                       'E'

#include "libftprintf.h"
#include "../mlx/mlx.h"
#include <stdio.h>
#include <stddef.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct      s_game
{
    char    **map;
    char    **player;
    void    *mlx_ptr;
	void    *mlx_win;
    void	*img_wall;
	void	*img_path;
	void	*img_player;
	void	*img_door;
}                   t_game;

char    **get_map_from_file(const char *file_name);
char    **fill_map(const char *file_name, char **map);
int     count_map_line(const char *file_name);
char    **get_memory_space_for_tab_line(size_t map_line);

void    check_file_extension(const char *file_name);
void    check_file_access(const char *file_name);
void    check_file_type(const char *file_name);
void    check_file(const char *file_name);

int     exit_routine(char **map, int error_nbr);
void    free_map(char **map);

void    check_first_last_line(char **map, size_t map_line);
void    check_len_line(char **map, size_t len_line);
void    check_map_component(char **map);
void    check_player(char **map);
void    check_exit(char **map);
void    check_collectible(char **map);
void    check_first_last_char(char **map, size_t last_char);
void    map_check(char **map, size_t map_line);

void    print_map(t_game **game);








#endif
