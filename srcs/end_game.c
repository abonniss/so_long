/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:41:42 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/05 17:41:47 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

void    ft_check_end_game(t_game *game)
{
    if (game->collectible == 0)
    {
        mlx_destroy_window(game->mlx_ptr, game->mlx_win);
        free_map(game->map);
        free(game->mlx_ptr);
        exit(EXIT_SUCCESS);
        return ;
    }
}
