/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:09:16 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/09 18:09:21 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

void	check_exit(char **map)
{
	size_t	i;
	size_t	line;
	size_t	nbr_exit;

	line = 0;
	nbr_exit = 0;
	while (map[line] != NULL)
	{
		i = 0;
		while (map[line][i] != '\0')
		{
			if (map[line][i] == EXIT)
				++nbr_exit;
			++i;
		}
		++line;
	}
	if (nbr_exit != 1)
		exit_routine(map, ERR_TOO_MANY_EXIT);
}

void	check_collectible(char **map)
{
	size_t	i;
	size_t	line;
	size_t	nbr_collectible;

	line = 0;
	nbr_collectible = 0;
	while (map[line] != NULL)
	{
		i = 0;
		while (map[line][i] != '\0')
		{
			if (map[line][i] == COLLECTIBLE)
				++nbr_collectible;
			++i;
		}
		++line;
	}
	if (nbr_collectible == 0)
		exit_routine(map, ERR_NO_COLLECTIBLE);
}

void	check_first_last_char(char **map, size_t last_char)
{
	size_t	line;
	size_t	first_char;

	line = 0;
	first_char = 0;
	while (map[line] != NULL)
	{
		if (map[line][first_char] != WALL || map[line][last_char] != WALL)
			exit_routine(map, ERR_NO_WALL);
		++line;
	}
}

void	map_check(char **map, size_t map_line)
{
	size_t	line;
	size_t	len_map_line;

	line = 0;
	len_map_line = ft_strlen(map[line]);
	check_map_component(map, len_map_line - 1);
	check_len_line(map, len_map_line);
	check_first_last_line(map, map_line);
	check_first_last_char(map, len_map_line - 1);
	check_player(map);
	check_exit(map);
	check_collectible(map);
}
