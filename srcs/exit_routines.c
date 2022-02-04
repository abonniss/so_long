/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_routines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:30:16 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/03 12:30:21 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

void exit_mlx(t_game **game)
{
	free_map((*game)->map);
	if ((*game)->mlx_ptr != NULL)
		free((*game)->mlx_ptr);
	if ((*game)->mlx_win != NULL)
		free((*game)->mlx_win);
	free(game);
	ft_putendl_fd("MLX Error", STDERR_FILENO);
}

int exit_routine(char **map, int error_nbr)
{
	const char *error_msgs[] = {NULL, ERR_MSG_MAP_EMPTY, ERR_MSG_MALLOC, ERR_MSG_WRONG_EXTENSION,
								ERR_MSG_TOO_SMALL, ERR_MSG_NO_WALL, ERR_MSG_NOT_RECTANGLE,
								ERR_MSG_BAD_FD, ERR_MSG_WRG_COMP, ERR_MSG_TOO_MANY_PLAYER,
								ERR_MSG_TOO_MANY_EXIT, ERR_MSG_NO_COLLECTIBLE};
	
	ft_putendl_fd((char*)error_msgs[error_nbr], STDERR_FILENO);
	if (map != NULL)
		free_map(map);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void free_map(char **map)
{
	size_t i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		++i;
	}
}
