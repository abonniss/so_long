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

int exit_routine(t_map **game, int exit_code)
{
	if (exit_code == MAP_EMPTY)
	{
		ft_dprintf(STDERR_FILENO, "The map is empty\n");
		free(*game);
		exit(exit_code);
	}
	if (exit_code == MALLOC_ERROR) // THIS
	{
		ft_dprintf(STDERR_FILENO, "Malloc allocation error\n");
		free(*game);
		exit(exit_code);
	}
	if (exit_code == WRONG_EXTENSION) // THIS
	{
		ft_dprintf(STDERR_FILENO, "Extension incorrect\n");
		free(*game);
		exit(exit_code);
	}
	if (exit_code == MAP_SMALL) // THIS
	{
		ft_dprintf(STDERR_FILENO, "La map ne contient pas assez de lignes\n");
		free(*game);
		exit(exit_code);
	}
	if (exit_code == NO_WALL) // THIS
	{
		ft_dprintf(STDERR_FILENO, "La Map n'est pas entoure de Mur\n");
		free(*game);
		exit(exit_code);
	}
	if (exit_code == NO_RECTANGLE) // THIS
	{
		ft_dprintf(STDERR_FILENO, "La Map n'est pas un rectangle\n");
		free(*game);
		exit(exit_code);
	}
	return(exit_code);
}

void free_tab_str(t_map **game, int exit_code)
{
	int i;

	i = 0;
	while (i <= (*game)->map_line)
	{
		free((*game)->map[i]);
		++i;
	}
	exit_routine(game, exit_code);
}

//pourquoi mettre file_name == NULL ? Alors que deja check avant dans main ? 
bool check_file_extension(t_map **game, const char *file_name, int *fd)
{
	size_t name_len;
	size_t i;

	*fd = open(file_name, O_RDONLY);
	if (*fd == -1 || file_name == NULL || ft_strlen(file_name) <= EXTENSION_LEN)
		return (false);
	name_len = ft_strlen(file_name);
	i = 0;
	//remplacer par strncmp
	while (i <= EXTENSION_LEN)
	{
		if ((file_name[(name_len - EXTENSION_LEN) + i] != EXTENSION_NAME[i]))
		{
			exit_routine(game, WRONG_EXTENSION);
			return (false);
		}
		++i;
	}
	return (true);
}

t_map *create_map(void)
{
	t_map *new_game;

	new_game = ft_calloc(1, sizeof(t_map));
	if (new_game == NULL)
		return (NULL);
	new_game->map = NULL;
	new_game->player = NULL;
	return (new_game);
}

int count_map_line(t_map **game, int fd)
{
	char	*str;
	int		i;
	
	i = 0;
	while (ft_get_next_line(fd, &str) > 0)
		++i;
	close(fd);
	if (i == 0)
		return (exit_routine(game, MAP_EMPTY));
	if (i == 1 || i == 2)
		return (exit_routine(game, MAP_SMALL));
	(*game)->map_line = i;
	return (i);
}

char **get_memory_space_for_tab_line(t_map **game, size_t tab_line)
{
	char **tab;

	tab = (char **)malloc(sizeof(char*) * tab_line);
	if (tab == NULL)
		exit_routine(game, MALLOC_ERROR);
	return (tab);
}

void check_first_last_line(t_map **game)
{
	int	line;
	size_t	index;

	line = 0;
	while ((*game)->map[line] != NULL)
	{
		index = 0;
		while ((*game)->map[line][index] != '\0')
		{
			if ((*game)->map[line][index] != WALL)
			{
				free_tab_str(game, NO_WALL);
			}
			++index;
		}
		if (line == (int)(*game)->map_line)
			break;
		line = (*game)->map_line;
	}
}

void check_len_line(t_map **game, size_t len_line)
{
	size_t i;

	i = 0;
	while ((*game)->map[i] != NULL)
	{
		if (ft_strlen((*game)->map[i]) != len_line)
			free_tab_str(game, NO_RECTANGLE);
		++i;
	}
}

bool is_map_correct(t_map **game)
{
	size_t i;
	size_t len_map_line;

	i = 0;
	len_map_line = ft_strlen((*game)->map[i]);
	check_first_last_line(game);
	//check_len_line(game, len_map_line);
	// while ((*game)->map[i] != NULL)
	// {
	// 	if (i == 0)
	// 		if (wall_check)
	// }
	return (true);
}

void parse_and_check_file_content(const char *file_name, int *fd, t_map **game)
{
	size_t	tab_line;
	size_t	i;
	char 	*str;

	i = 0;
	tab_line = count_map_line(game, *fd);
	(*game)->map = get_memory_space_for_tab_line(game, tab_line);
	*fd = open(file_name, O_RDONLY);
	while (ft_get_next_line(*fd, &str) > 0 && i <= tab_line)
	{
		(*game)->map[i] = ft_strdup(str);
		if ((*game)->map[i] == NULL)
			free_tab_str(game, MALLOC_ERROR);
		++i;
	}
	is_map_correct(game);
	
}

int main (int argc, char **argv)
{
	int		fd;
	t_map	*game;

	fd = 0;
	game = create_map();
	if (argc != 2 || check_file_extension(&game, argv[1], &fd) != true || game == NULL)
	{
		ft_printf("ERROR");
		return (EXIT_FAILURE);
	}
	parse_and_check_file_content(argv[1], &fd, &game);




	

	return (EXIT_SUCCESS);
}