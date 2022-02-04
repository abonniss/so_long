

void    set_player_position(t_game **game)
{
	size_t i;
	size_t line;

	line = 0;
	while (map[line] != NULL)
	{
		i = 0;
		while (map[line][i] != '\0')
		{
			if (map[line][i] == PLAYER)
            {
                (*game)->y_player = line;
                (*game)->x_player = i;
            }
			++i;
		}
		++line;
	}
}