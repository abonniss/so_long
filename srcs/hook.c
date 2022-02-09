/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:41:14 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/09 17:42:44 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W_UP)
		ft_move_up(game);
	else if (keycode == KEY_S_DOWN)
		ft_move_down(game);
	else if (keycode == KEY_A_LEFT)
		ft_move_left(game);
	else if (keycode == KEY_D_RIGHT)
		ft_move_right(game);
	else if (keycode == KEY_ESC)
		ft_escape_key_and_wcross(game);
	return (0);
}

void	hook_event(t_game *game)
{
	mlx_hook(game->mlx_win, 2, 1L << 0, ft_key_press, game);
	mlx_hook(game->mlx_win, 17, 0, ft_escape_key_and_wcross, game);
	mlx_hook(game->mlx_win, 12, 1L << 15, ft_minimize, game);
}
