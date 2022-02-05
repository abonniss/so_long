#include  "so_long.h"

void    set_player_position(t_game **game)
{
	size_t i;
	size_t line;

	line = 0;
	while ((*game)->map[line] != NULL)
	{
		i = 0;
		while ((*game)->map[line][i] != '\0')
		{
			if ((*game)->map[line][i] == PLAYER)
            {
                (*game)->y_player = line;
                (*game)->x_player = i;
            }
			++i;
		}
		++line;
	}
}