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

t_game *create_map(void)
{
	t_game *new_game;

	new_game = ft_calloc(1, sizeof(t_game));
	if (new_game == NULL)
		return (NULL);
	return (new_game);
}

int main (int argc, char **argv)
{
	char 	**map;
	t_game	*game;

	map = NULL;
	if (argc != 2)
		return (EXIT_FAILURE);
	check_file(argv[1]);
	map = get_map_from_file(argv[1]);
	game = create_map();
	if (map == NULL || game == NULL)
		return (EXIT_FAILURE);
	game->map = map;
	// print_map(&game);
	


	return (EXIT_SUCCESS);
}