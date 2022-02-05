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

t_game *create_game(void)
{
	t_game *new_game;

	new_game = ft_calloc(1, sizeof(t_game));
	if (new_game == NULL)
		return (NULL);
	new_game->xpm_data_ground = IMG_PATH_GROUND;
	new_game->xpm_data_wall = IMG_PATH_WALL;
	new_game->xpm_data_player = IMG_PATH_PLAYER;
	new_game->xpm_data_door = IMG_PATH_DOOR;
	new_game->xpm_data_collec = IMG_PATH_COLLECTIBLE;
	new_game->img_width = 100;
	new_game->img_height = 100;
	new_game->collectible = 0;
	return (new_game);
}

int main (int argc, char **argv)
{
	char 	**map;
	t_game	*game;

	map = NULL;
	if (argc != 2)
		return (EXIT_FAILURE);
	check_file(argv[1]);
	if (check_image_access() == false)
		return(EXIT_FAILURE);
	map = get_map_from_file(argv[1]);
	if (map == NULL)
		exit_routine(NULL, ERR_MALLOC);
	game = create_game();
	if (game == NULL)
		exit_routine(map, ERR_MALLOC);
	game->map = map;
	initializer(&game);
	map_initializer(&game);
	
	return (EXIT_SUCCESS);
}
