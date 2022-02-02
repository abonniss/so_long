/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:05:53 by abonniss          #+#    #+#             */
/*   Updated: 2022/01/21 21:53:36 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

int exit_routine(t_game **game, int error_nbr)
{
	const char *error_msgs[] = {NULL, ERR_MSG_MAP_EMPTY, ERR_MSG_MALLOC, ERR_MSG_WRONG_EXTENSION,
								ERR_MSG_TOO_SMALL, ERR_MSG_NO_WALL, ERR_MSG_NOT_RECTANGLE,
								ERR_MSG_BAD_FD};
	
	ft_putendl_fd((char*)error_msgs[error_nbr], STDERR_FILENO);
	free(*game);
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

bool check_file_extension(t_game **game, const char *file_name)
{	
	size_t name_len;
	size_t i;

	name_len = ft_strlen(file_name);
	i = 0;
	if (name_len <= EXTENSION_LEN)
		exit_routine(game, ERR_WRONG_EXTENSION);
	while (i <= EXTENSION_LEN)
	{
		if ((file_name[(name_len - EXTENSION_LEN) + i] != EXTENSION_NAME[i]))
		{
			exit_routine(game, ERR_WRONG_EXTENSION);
			return (false);
		}
		++i;
	}
	return (true);
}

t_game *create_map(void)
{
	t_game *new_game;

	new_game = ft_calloc(1, sizeof(t_game));
	if (new_game == NULL)
		return (NULL);
	new_game->map = NULL;
	new_game->player = NULL;
	return (new_game);
}

int count_map_line(const char *file_name, t_game **game)
{
	char	*str;
	int		i;
	int 	fd;
	
	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == BAD_FILE_DESCRIPTOR)
		exit_routine(game, ERR_BAD_FD);
	while (ft_get_next_line(fd, &str) > 0)
		++i;
	close(fd);
	if (i == 0)
		return (exit_routine(game, ERR_MAP_EMPTY));
	if (i == 1 || i == 2)
		return (exit_routine(game, ERR_TOO_SMALL));
	(*game)->map_line = i;
	return (i);
}

char **get_memory_space_for_tab_line(t_game **game, size_t map_line)
{
	char **map;

	map = (char **)malloc(sizeof(char*) * map_line + 1);
	if (map== NULL)
		exit_routine(game, ERR_MALLOC);
	map[map_line] = NULL;
	return (map);
}

void check_first_last_line(t_game **game)
{
	size_t	line;
	size_t	index;

	line = 0;
	while ((*game)->map[line] != NULL)
	{
		index = 0;
		while ((*game)->map[line][index] != '\0')
		{
			if ((*game)->map[line][index] != WALL)
			{
				free_map((*game)->map);
				exit_routine(game, ERR_NO_WALL);
			}
			++index;
		}
		if (line == (*game)->map_line)
			break;
		line = (*game)->map_line;
	}
}

void check_len_line(t_game **game, size_t len_line)
{
	size_t i;

	i = 0;
	while ((*game)->map[i] != NULL)
	{
		if (ft_strlen((*game)->map[i]) != len_line)
		{
			free_map((*game)->map);
			exit_routine(game, ERR_NOT_RECTANGLE);
		}
		++i;
	}
}

void check_first_last_char(char **map, size_t last_char, t_game **game)
{
	size_t	line;
	size_t	first_char;

	line = 0;
	first_char = 0;
	while (map[line] != NULL)
	{
		if (map[line][first_char] != WALL || map[line][last_char] != WALL)
		{
			free_map(map);
			exit_routine(game, ERR_NO_WALL);
		}
		++line;
	}
}

void is_map_correct(t_game **game)
{
	size_t i;
	size_t len_map_line;

	i = 0;
	len_map_line = ft_strlen((*game)->map[i]);
	check_len_line(game, len_map_line);
	check_first_last_line(game);
	check_first_last_char((*game)->map, len_map_line - 1, game);

}

char **fill_map(const char *file_name, char **map, t_game **game)
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
		{
			free_map(map);
			exit_routine(game, ERR_MALLOC);
		}
		++i;
	}
	close(fd);
	return (map);
}

void get_map_from_file(const char *file_name, t_game **game)
{
	size_t	map_line;
	char	**map;

	map_line = count_map_line(file_name, game);
	map = get_memory_space_for_tab_line(game, map_line);
	if (map == NULL)
		exit_routine(game, ERR_MALLOC);
	check_file_extension(game, file_name);
	(*game)->map = fill_map(file_name, map, game);
	is_map_correct(game);

	
}

int main (int argc, char **argv)
{
	t_game	*game;

	game = create_map();
	if (argc != 2 || game == NULL)
		return (EXIT_FAILURE);
	get_map_from_file(argv[1], &game);




	

	return (EXIT_SUCCESS);
}