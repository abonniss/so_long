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
    (*game)->img_ground = mlx_xpm_file_to_image((*game)->mlx_ptr, (*game)->xpm_data_ground, &(*game)->img_width, &(*game)->img_height);
	(*game)->img_wall = mlx_xpm_file_to_image((*game)->mlx_ptr, (*game)->xpm_data_wall, &(*game)->img_width, &(*game)->img_height);
	(*game)->img_player = mlx_xpm_file_to_image((*game)->mlx_ptr, (*game)->xpm_data_player, &(*game)->img_width, &(*game)->img_height);
	(*game)->img_door = mlx_xpm_file_to_image((*game)->mlx_ptr, (*game)->xpm_data_door, &(*game)->img_width, &(*game)->img_height);
	(*game)->img_collec = mlx_xpm_file_to_image((*game)->mlx_ptr, (*game)->xpm_data_collec, &(*game)->img_width, &(*game)->img_height);
}

void destroy_images(t_game **game)
{
	mlx_destroy_image((*game)->mlx_ptr, (*game)->img_wall);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->img_ground);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->img_player);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->img_door);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->img_collec);
}

void display_map(t_game **game)
{
	get_images(game);
	display_wall(game);
	display_ground(game);
	display_player(game);
	display_door(game);
	display_collectible(game);
	destroy_images(game);
}

void map_initializer(t_game **game)
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