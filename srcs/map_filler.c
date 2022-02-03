/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:30:42 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/03 12:30:47 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

char **get_memory_space_for_tab_line(size_t map_line)
{
	char **map;

	map = (char **)malloc(sizeof(char*) * map_line + 1);
	if (map== NULL)
		exit_routine(NULL, ERR_MALLOC);
	map[map_line] = NULL;
	return (map);
}

int count_map_line(const char *file_name)
{
	char	*str;
	int		i;
	int 	fd;
	
	i = 0;
	fd = open(file_name, O_RDONLY);
	while (ft_get_next_line(fd, &str) > 0)
		++i;
	close(fd);
	if (i == 0)
		return (exit_routine(NULL, ERR_MAP_EMPTY));
	if (i == 1 || i == 2)
		return (exit_routine(NULL, ERR_TOO_SMALL));
	return (i);
}

char **fill_map(const char *file_name, char **map)
{
	char 	*str;
	size_t	i;
	int		fd;
	
	i = 0;
	fd = open(file_name, O_RDONLY);
	str = NULL;
	while (ft_get_next_line(fd, &str) > 0)
	{
		map[i] = ft_strdup(str);
		if (map[i] == NULL)
			exit_routine(map, ERR_MALLOC);
		++i;
	}
	close(fd);
	return (map);
}

char **get_map_from_file(const char *file_name)
{
	size_t	map_line;
	char	**map;

	map = NULL;
	map_line = count_map_line(file_name);
	map = get_memory_space_for_tab_line(map_line);
	fill_map(file_name, map);
	map_check(map, map_line);
	return (map);
}
