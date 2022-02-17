/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:41:42 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/09 17:31:15 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

void	final_map_change(t_game *game, size_t line, size_t i, int move)
{
	if (move == MV_UP)
	{
		game->map[line - 1][i] = 'P';
		game->map[line][i] = '0';
	}
	else if (move == MV_DW)
	{
		game->map[line + 1][i] = 'P';
		game->map[line][i] = '0';
	}
	else if (move == MV_LFT)
	{
		game->map[line][i - 1] = 'P';
		game->map[line][i] = '0';
	}
	else if (move == MV_RGT)
	{
		game->map[line][i + 1] = 'P';
		game->map[line][i] = '0';
	}
}

void	ft_check_end_game(t_game *game, size_t line, size_t i, int move)
{
	size_t	time;

	time = 10;
	if (game->collectible == 0)
	{
		game->end = true;
		final_map_change(game, line, i, move);
		while (--time != 0)
			display_map(game);
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		free_map(game->map);
		free(game->mlx_ptr);
		exit(EXIT_SUCCESS);
		return ;
	}
}
