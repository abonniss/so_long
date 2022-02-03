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

// void get_image(t_game **game)
// {
    	// char	*xpm_data_path = "./img/aub.xpm";
	    // char	*xpm_data_wall = "./img/choco.xpm";
	    // char	*xpm_data_player = "./img/player.xpm";
	    // char	*xpm_data_door = "./img/door.xpm";
	    // int		img_width = 100;
	    // int		img_height = 100;
//     img_path = mlx_xpm_file_to_image(mlx_ptr, xpm_data_path, &img_width, &img_height);
// 	img_wall = mlx_xpm_file_to_image(mlx_ptr, xpm_data_wall, &img_width, &img_height);
// 	img_player = mlx_xpm_file_to_image(mlx_ptr, xpm_data_player, &img_width, &img_height);
// 	img_door = mlx_xpm_file_to_image(mlx_ptr, xpm_data_door, &img_width, &img_height);
// 	if (img_wall == NULL || img_path == NULL)
// 	{
// 		mlx_destroy_display(mlx_ptr);
// 		free(mlx_ptr);
// 	}
// }


void print_map(t_game **game)
{
    (*game)->mlx_ptr = mlx_init();
	// if ((*game)->mlx_ptr == NULL)
	// 	return (MLX_ERROR);
    (*game)->mlx_win = mlx_new_window((*game)->mlx_ptr, WINDOW_WIDHT, WINDOW_HEIGHT, 
				"My First Window");
    // get_images(game);
    
}