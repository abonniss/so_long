#include  "so_long.h"

void display_wall(t_game *game)
{
	size_t i;
	size_t x;
	size_t y;
	size_t line;

	line = 0;
	y = 0;
	get_image_wall(game);
	while (game->map[line] != NULL)
	{
		i = 0;
		x = 0;
		while (game->map[line][i] != '\0')
		{
			if (game->map[line][i] == '1')
				mlx_put_image_to_window(game->mlx_ptr,
				game->mlx_win, game->img_wall, x, y);
			x += IMG_SIZE_PXL;
			++i;
		}
		y += IMG_SIZE_PXL;
		++line;
	}
	mlx_destroy_image(game->mlx_ptr, game->img_wall);
}

void display_ground(t_game *game)
{
	size_t i;
	size_t x;
	size_t y;
	size_t line;

	line = 0;
	y = 0;
	get_image_ground(game);
	while (game->map[line] != NULL)
	{
		i = 0;
		x = 0;
		while (game->map[line][i] != '\0')
		{
			if (game->map[line][i] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_ground, x, y);
			x += IMG_SIZE_PXL;
			++i;
		}
		y += IMG_SIZE_PXL;
		++line;
	}
	mlx_destroy_image(game->mlx_ptr, game->img_ground);
}

void display_player(t_game *game)
{
	size_t i;
	size_t x;
	size_t y;
	size_t line;

	line = 0;
	y = 0;
	get_image_player(game);
	while (game->map[line] != NULL)
	{
		i = 0;
		x = 0;
		while (game->map[line][i] != '\0')
		{
			if (game->map[line][i] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, x, y);
			x += IMG_SIZE_PXL;
			++i;
		}
		y += IMG_SIZE_PXL;
		++line;
	}
	mlx_destroy_image(game->mlx_ptr, game->img_player);
}

void display_door(t_game *game)
{
	size_t i;
	size_t x;
	size_t y;
	size_t line;

	line = 0;
	y = 0;
	get_image_door(game);
	while (game->map[line] != NULL)
	{
		i = 0;
		x = 0;
		while (game->map[line][i] != '\0')
		{
			if (game->map[line][i] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_door, x, y);
			x += IMG_SIZE_PXL;
			++i;
		}
		y += IMG_SIZE_PXL;
		++line;
	}
	mlx_destroy_image(game->mlx_ptr, game->img_door);
}

void display_collectible(t_game *game)
{
	size_t i;
	size_t x;
	size_t y;
	size_t line;

	line = 0;
	y = 0;
	get_image_collec(game);
	while (game->map[line] != NULL)
	{
		i = 0;
		x = 0;
		while (game->map[line][i] != '\0')
		{
			if (game->map[line][i] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_collec, x, y);
			x += IMG_SIZE_PXL;
			++i;
		}
		y += IMG_SIZE_PXL;
		++line;
	}
	mlx_destroy_image(game->mlx_ptr, game->img_collec);
}