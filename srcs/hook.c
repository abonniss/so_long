#include  "so_long.h"

void ft_move_up(t_game **game)
{
    size_t i;
	size_t line;
    
    i = (*game)->x_player;
    line = (*game)->y_player;
    if ((*game)->map[line - 1][i] == 'C' || (*game)->map[line - 1][i] == '0')
    {
        (*game)->map[line - 1][i] = 'P';
        (*game)->y_player -= 1;
        (*game)->map[line][i] = '0';
        (*game)->count++;
        display_map(game);
    }
}

void ft_move_down(t_game **game)
{
    size_t i;
	size_t line;
    
    i = (*game)->x_player;
    line = (*game)->y_player;
    if ((*game)->map[line + 1][i] == 'C' || (*game)->map[line + 1][i] == '0')
    {
        (*game)->map[line + 1][i] = 'P';
        (*game)->y_player += 1;
        (*game)->map[line][i] = '0';
        (*game)->count++;
        display_map(game);
    }
}

void ft_move_left(t_game **game)
{
    size_t i;
	size_t line;
    
    i = (*game)->x_player;
    line = (*game)->y_player;
    if ((*game)->map[line][i - 1] == 'C' || (*game)->map[line][i - 1] == '0')
    {
        (*game)->map[line][i - 1] = 'P';
        (*game)->x_player -= 1;
        (*game)->map[line][i] = '0';
        (*game)->count++;
        display_map(game);
    }
}

void ft_move_right(t_game **game)
{
    size_t i;
	size_t line;
    
    i = (*game)->x_player;
    line = (*game)->y_player;
    if ((*game)->map[line][i + 1] == 'C' || (*game)->map[line][i + 1] == '0')
    {
        (*game)->map[line][i + 1] = 'P';
        (*game)->x_player += 1;
        (*game)->map[line][i] = '0';
        (*game)->count++;
        display_map(game);
    }
}

int    ft_move(int keycode, t_game **game)
{
    if (keycode == KEY_W_UP)
		ft_move_up(game);
    else if (keycode == KEY_S_DOWN)
        ft_move_down(game);
    else if (keycode == KEY_A_LEFT)
        ft_move_left(game);
    else if (keycode == KEY_D_RIGHT)
        ft_move_right(game);
    return (0);
}

void    hook_event(t_game **game)
{
        mlx_hook((*game)->mlx_win, 2, 1L << 0, ft_move, game);
    	// mlx_hook((*game)->mlx_win, 17, 0, ft_escape, game);
        // mlx_hook((*game)->mlx_win, 12, 1L << 15, ft_minimize, game);
}