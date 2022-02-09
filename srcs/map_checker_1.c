/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:09:29 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/09 18:09:40 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

void	check_first_last_line(char **map, size_t map_line)
{
	size_t	line;
	size_t	index;

	line = 0;
	while (map[line] != NULL)
	{
		index = 0;
		while (map[line][index] != '\0')
		{
			if (map[line][index] != WALL)
				exit_routine(map, ERR_NO_WALL);
			++index;
		}
		if (line == map_line)
			break ;
		line = map_line;
	}
}

void	check_len_line(char **map, size_t len_line)
{
	size_t	i;

	i = 0;
	while (map[i] != NULL)
	{
		if (ft_strlen((map[i])) != len_line)
			exit_routine(map, ERR_NOT_RECTANGLE);
		++i;
	}
}

void	check_map_component(char **map, size_t last_char)
{
	size_t	i;
	size_t	line;

	line = 0;
	while (map[line] != NULL)
	{
		i = 0;
		while (i < last_char)
		{
			if (map[line][i] != WALL && map[line][i] != EMPTY && map[line][i]
				!= PLAYER && map[line][i] != COLLECTIBLE && map[line][i]
				!= EXIT)
				exit_routine(map, ERR_WRG_COMP);
			++i;
		}
		++line;
	}
}

void	check_player(char **map)
{
	size_t	i;
	size_t	line;
	size_t	nbr_player;

	line = 0;
	nbr_player = 0;
	while (map[line] != NULL)
	{
		i = 0;
		while (map[line][i] != '\0')
		{
			if (map[line][i] == PLAYER)
				nbr_player++;
			++i;
		}
		++line;
	}
	if (nbr_player != 1)
		exit_routine(map, ERR_TOO_MANY_PLAYER);
}
