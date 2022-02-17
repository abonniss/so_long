/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_components.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:20:14 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/09 17:25:28 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

void	display_wall(t_game *game)
{
	size_t	col;
	size_t	line;

	line = 0;
	get_image_wall(game);
	while (game->map[line] != NULL)
	{
		col = 0;
		while (game->map[line][col] != '\0')
		{
			if (game->map[line][col] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					game->img_wall, col * IMG_SIZE_PXL, line * IMG_SIZE_PXL);
			++col;
		}
		++line;
	}
	mlx_destroy_image(game->mlx_ptr, game->img_wall);
}

void	display_ground(t_game *game)
{
	size_t	col;
	size_t	line;

	line = 0;
	get_image_ground(game);
	while (game->map[line] != NULL)
	{
		col = 0;
		while (game->map[line][col] != '\0')
		{			
			if (game->map[line][col] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					game->img_ground, col * IMG_SIZE_PXL, line * IMG_SIZE_PXL);
			++col;
		}
		++line;
	}
	mlx_destroy_image(game->mlx_ptr, game->img_ground);
}

void	display_player(t_game *game)
{
	size_t	col;
	size_t	line;

	line = 0;
	get_image_player(game);
	while (game->map[line] != NULL)
	{
		col = 0;
		while (game->map[line][col] != '\0')
		{
			if (game->map[line][col] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					game->img_player, col * IMG_SIZE_PXL, line * IMG_SIZE_PXL);
			++col;
		}
		++line;
	}
	mlx_destroy_image(game->mlx_ptr, game->img_player);
}

void	display_door(t_game *game)
{
	size_t	col;
	size_t	line;

	line = 0;
	get_image_door(game);
	while (game->map[line] != NULL)
	{
		col = 0;
		while (game->map[line][col] != '\0')
		{
			if (game->map[line][col] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					game->img_door, col * IMG_SIZE_PXL, line * IMG_SIZE_PXL);
			++col;
		}
		++line;
	}
	mlx_destroy_image(game->mlx_ptr, game->img_door);
}

void	display_collectible(t_game *game)
{
	size_t	col;
	size_t	line;

	line = 0;
	get_image_collec(game);
	while (game->map[line] != NULL)
	{
		col = 0;
		while (game->map[line][col] != '\0')
		{
			if (game->map[line][col] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					game->img_collec, col * IMG_SIZE_PXL, line * IMG_SIZE_PXL);
			++col;
		}
		++line;
	}
	mlx_destroy_image(game->mlx_ptr, game->img_collec);
}
