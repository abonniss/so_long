/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:30:18 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/08 19:30:23 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

void get_image_collec(t_game *game)
{
	game->img_collec = mlx_xpm_file_to_image(game->mlx_ptr, game->xpm_data_collec, &game->img_width, &game->img_height);

	if (game->img_collec == NULL)
		return (exit_mlx(game));
}

void get_image_wall(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, game->xpm_data_wall, &game->img_width, &game->img_height);

	if (game->img_wall == NULL)
		return (exit_mlx(game));
}

void get_image_ground(t_game *game)
{
    game->img_ground = mlx_xpm_file_to_image(game->mlx_ptr, game->xpm_data_ground, &game->img_width, &game->img_height);

	if (game->img_ground == NULL)
		return (exit_mlx(game));
}

void get_image_player(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, game->xpm_data_player, &game->img_width, &game->img_height);

	if (game->img_player == NULL)
		return (exit_mlx(game));
}

void get_image_door(t_game *game)
{
	game->img_door = mlx_xpm_file_to_image(game->mlx_ptr, game->xpm_data_door, &game->img_width, &game->img_height);

	if (game->img_door == NULL)
		return (exit_mlx(game));
}
