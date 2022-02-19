/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:02:13 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/09 18:42:10 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define GAME_NAME					"Terminator"

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
# define ERR_MSG_TOO_SMALL          "The MAP doesn't have enough line"

# define ERR_NO_WALL                5
# define ERR_MSG_NO_WALL            "The MAP has a breach"

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

# define KEY_W_UP                   119
# define KEY_S_DOWN                 115
# define KEY_A_LEFT                 97
# define KEY_D_RIGHT                100
# define KEY_ESC	                65307

# define MV_UP   					1
# define MV_DW   					2
# define MV_RGT    					3
# define MV_LFT   					4

# define NBR_IMAGES   				5
# define IMG_PATH_PLAYER			"./img/player.xpm"
# define IMG_PATH_DOOR				"./img/door.xpm"
# define IMG_PATH_COLLECTIBLE		"./img/collectible.xpm"
# define IMG_PATH_WALL				"./img/wall.xpm"
# define IMG_PATH_GROUND			"./img/path.xpm"

# define IMG_SIZE_PXL				40

# define CHARSET					"10PEC"

# include "libftprintf.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <stddef.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_game
{
	char	**map;
	char	**player;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_wall;
	void	*img_ground;
	void	*img_player;
	void	*img_door;
	void	*img_collec;
	char	*xpm_data_ground;
	char	*xpm_data_wall;
	char	*xpm_data_player;
	char	*xpm_data_door;
	char	*xpm_data_collec;
	int		img_width;
	int		img_height;
	bool	end;
	size_t	y_player;
	size_t	x_player;
	size_t	move_count;
	size_t	collectible;
	size_t	map_rows;
	size_t	map_lines;
}			t_game;

char	**get_map_from_file(const char *file_name, t_game *game);
char	**fill_map(const char *file_name, char **map);
int		count_map_line(const char *file_name);
char	**get_memory_space_for_tab_line(size_t map_line);

void	check_file_extension(const char *file_name);
void	check_file_access(const char *file_name);
void	check_file_type(const char *file_name);
void	check_file(const char *file_name);

bool	check_image_access(void);

int		exit_routine(char **map, int error_nbr);
void	exit_mlx(t_game *game);
void	free_map(char **map);

void	check_first_last_line(char **map, size_t map_line);
void	check_len_line(char **map, size_t len_line);
void	check_map_component(char **map, size_t map_line);
void	check_player(char **map);
void	check_exit(char **map);
void	check_collectible(char **map);
void	check_first_last_char(char **map, size_t last_char);
void	map_check(char **map, size_t map_line);

void	set_player_position(t_game *game);

void	display_map(t_game *game);
void	map_initializer(t_game *game);

void	get_image_wall(t_game *game);		
void	get_image_ground(t_game *game);	
void	get_image_player(t_game *game);
void	get_image_door(t_game *game);
void	get_image_collec(t_game *game);

void	display_ground(t_game *game);
void	display_player(t_game *game);
void	display_door(t_game *game);
void	display_wall(t_game *game);
void	display_collectible(t_game *game);

int		ft_escape_key_and_wcross(t_game *game);
int		ft_minimize(t_game *game);

void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);

void	hook_event(t_game *game);
void	initializer(t_game *game);
void	ft_check_end_game(t_game *game, size_t line, size_t col, int move);

#endif
