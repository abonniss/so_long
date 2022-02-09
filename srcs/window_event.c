/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:01:54 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/08 21:01:56 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

int ft_escape_key_and_wcross(t_game *game)
{
    mlx_destroy_window(game->mlx_ptr, game->mlx_win);
    free_map(game->map);
    free(game->mlx_ptr);
    exit(EXIT_SUCCESS);
    return(0);
}

int ft_minimize(t_game *game)
{
    display_map(game);
    mlx_string_put(game->mlx_ptr, game->mlx_win, 10, 10, 0x00FF00, ft_itoa((int)game->move_count));
    return(EXIT_SUCCESS);
}
