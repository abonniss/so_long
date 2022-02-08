/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:58:40 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/03 15:58:42 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

void display_map(t_game *game)
{
	display_wall(game);
	display_ground(game);
	display_player(game);
	display_door(game);
	display_collectible(game);
}

void map_initializer(t_game *game)
{
    int	window_widht;
	int	window_height;

	window_height	= game->map_lines * IMG_SIZE_PXL;
	window_widht	= game->map_rows * IMG_SIZE_PXL;
	game->mlx_ptr	= mlx_init();
	if (game->mlx_ptr == NULL)
		return (exit_mlx(game));
    game->mlx_win = mlx_new_window(game->mlx_ptr, window_widht, window_height, 
				GAME_NAME);
	if (game->mlx_win == NULL)
		return (exit_mlx(game));
	display_map(game);
	hook_event(game);
	mlx_loop(game->mlx_ptr);
}