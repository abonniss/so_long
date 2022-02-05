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

void get_images(t_game **game)
{
    (*game)->img_path = mlx_xpm_file_to_image((*game)->mlx_ptr, (*game)->xpm_data_path, &(*game)->img_width, &(*game)->img_height);
	(*game)->img_wall = mlx_xpm_file_to_image((*game)->mlx_ptr, (*game)->xpm_data_wall, &(*game)->img_width, &(*game)->img_height);
	(*game)->img_player = mlx_xpm_file_to_image((*game)->mlx_ptr, (*game)->xpm_data_player, &(*game)->img_width, &(*game)->img_height);
	(*game)->img_door = mlx_xpm_file_to_image((*game)->mlx_ptr, (*game)->xpm_data_door, &(*game)->img_width, &(*game)->img_height);
	(*game)->img_collec = mlx_xpm_file_to_image((*game)->mlx_ptr, (*game)->xpm_data_collec, &(*game)->img_width, &(*game)->img_height);
}

void display_map(t_game **game)
{
	char **map;
	size_t i;
	size_t x;
	size_t y;
	size_t line;

	map = (*game)->map;
	line = 0;
	y = 0;
	get_images(game);
	while (map[line] != NULL)
	{
		i = 0;
		x = 0;
		while (map[line][i] != '\0')
		{
			if (map[line][i] == '1')
			{
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->mlx_win, (*game)->img_wall, x, y);
			}
			else if (map[line][i] == '0')
			{
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->mlx_win, (*game)->img_path, x, y);
			}
			else if (map[line][i] == 'P')
			{
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->mlx_win, (*game)->img_player, x, y);
			}
			else if (map[line][i] == 'E')
			{
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->mlx_win, (*game)->img_door, x, y);
			}
			else if (map[line][i] == 'C')
			{
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->mlx_win, (*game)->img_collec, x, y);
			}
			x += 16;
			++i;
		}
		y += 16;
		++line;
	}
	mlx_destroy_image((*game)->mlx_ptr, (*game)->img_wall);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->img_path);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->img_player);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->img_door);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->img_collec);
}


void print_map(t_game **game)
{
    (*game)->mlx_ptr = mlx_init();
	if ((*game)->mlx_ptr == NULL)
		return (exit_mlx(game));
    (*game)->mlx_win = mlx_new_window((*game)->mlx_ptr, WINDOW_WIDHT, WINDOW_HEIGHT, 
				"My First Window");
	if ((*game)->mlx_win == NULL)
		return (exit_mlx(game));
	display_map(game);
	hook_event(game);

	mlx_loop((*game)->mlx_ptr);
    
}