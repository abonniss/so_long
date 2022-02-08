/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:05:53 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/04 09:10:23 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

t_game init_game(void)
{
	t_game new_game;

	new_game.xpm_data_ground = IMG_PATH_GROUND;
	new_game.xpm_data_wall = IMG_PATH_WALL;
	new_game.xpm_data_player = IMG_PATH_PLAYER;
	new_game.xpm_data_door = IMG_PATH_DOOR;
	new_game.xpm_data_collec = IMG_PATH_COLLECTIBLE;
	new_game.img_width = 100;
	new_game.img_height = 100;
	new_game.collectible = 0;
	return (new_game);
}

int main (int argc, char **argv)
{
	char 	**map;
	t_game	game;

	map = NULL;
	game = init_game();
	if (argc != 2)
		return (EXIT_FAILURE);
	check_file(argv[1]);
	if (check_image_access() == false)
		exit_routine(NULL, ERR_BAD_FD);
	map = get_map_from_file(argv[1], &game);
	if (map == NULL)
		exit_routine(NULL, ERR_MALLOC);
	game.map = map;
	initializer(&game);
	map_initializer(&game);
	
	return (EXIT_SUCCESS);
}
