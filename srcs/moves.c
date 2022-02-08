/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:01:34 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/08 21:01:36 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include  "so_long.h"

void ft_move_up(t_game *game)
{
    size_t i;
	size_t line;
    
    i = game->x_player;
    line = game->y_player;
    if (game->map[line - 1][i] == 'C' || game->map[line - 1][i] == '0'
        || game->map[line - 1][i] == 'E')
    {
        if (game->map[line - 1][i] == 'C')
            game->collectible -= 1;
        if (game->map[line - 1][i] == 'E')
        {
            ft_check_end_game(game);
            return;
        }
        game->map[line - 1][i] = 'P';
        game->y_player -= 1;
        game->map[line][i] = '0';
        game->move_count++;
        display_map(game);
        mlx_string_put(game->mlx_ptr, game->mlx_win, 10, 10, 0x00FF00, ft_itoa((int)game->move_count));
        ft_printf("%d\n",game->move_count);
    }
}

void ft_move_down(t_game *game)
{
    size_t i;
	size_t line;
    
    i = game->x_player;
    line = game->y_player;
    if (game->map[line + 1][i] == 'C' || game->map[line + 1][i] == '0'
        || game->map[line + 1][i] == 'E')
    {
        if (game->map[line + 1][i] == 'C')
            game->collectible -= 1;
        if (game->map[line + 1][i] == 'E')
        {
            ft_check_end_game(game);
            return;
        }
        game->map[line + 1][i] = 'P';
        game->y_player += 1;
        game->map[line][i] = '0';
        game->move_count++;
        display_map(game);
        mlx_string_put(game->mlx_ptr, game->mlx_win, 10, 10, 0x00FF00, ft_itoa((int)game->move_count));
        ft_printf("%d\n",game->move_count);
    }
}

void ft_move_left(t_game *game)
{
    size_t i;
	size_t line;
    
    i = game->x_player;
    line = game->y_player;
    if (game->map[line][i - 1] == 'C' || game->map[line][i - 1] == '0'
        || game->map[line][i - 1] == 'E')
    {
        if (game->map[line][i - 1] == 'C')
            game->collectible -= 1;
        if (game->map[line][i - 1] == 'E')
        {
            ft_check_end_game(game);
            return;
        }
        game->map[line][i - 1] = 'P';
        game->x_player -= 1;
        game->map[line][i] = '0';
        game->move_count++;
        display_map(game);
        mlx_string_put(game->mlx_ptr, game->mlx_win, 10, 10, 0x00FF00, ft_itoa((int)game->move_count));
        ft_printf("%d\n",game->move_count);
    }
}

void ft_move_right(t_game *game)
{
    size_t i;
	size_t line;
    
    i = game->x_player;
    line = game->y_player;
    if (game->map[line][i + 1] == 'C' || game->map[line][i + 1] == '0'
        || game->map[line][i + 1] == 'E')
    {
        if (game->map[line][i + 1] == 'C')
            game->collectible -= 1;
        if (game->map[line][i + 1] == 'E')
        {
            ft_check_end_game(game);
            return;
        }
        game->map[line][i + 1] = 'P';
        game->x_player += 1;
        game->map[line][i] = '0';
        game->move_count++;
        display_map(game);
        mlx_string_put(game->mlx_ptr, game->mlx_win, 10, 10, 0x00FF00, ft_itoa((int)game->move_count));
        ft_printf("%d\n",game->move_count);
    }
}
