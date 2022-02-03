# define MAX_ROW 6
# define MAX_COLUMN 10

int main (void)
{
	void *mlx_ptr;
	void *mlx_win;
	// t_data	img;
	void	*img_wall;
	void	*img_path;
	void	*img_player;
	void	*img_door;
	char	*xpm_data_path = "./img/aub.xpm";
	char	*xpm_data_wall = "./img/choco.xpm";
	char	*xpm_data_player = "./img/player.xpm";
	char	*xpm_data_door = "./img/door.xpm";
	// void	*position;
	int		img_width = 100;
	int		img_height = 100;
	int 	x;
	int 	y;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	mlx_win = mlx_new_window(mlx_ptr, WINDOW_WIDHT, WINDOW_HEIGHT, 
				"My First Window");
	if (mlx_win == NULL)
	{
		free(mlx_win);
		return (MLX_ERROR);
	}
	img_path = mlx_xpm_file_to_image(mlx_ptr, xpm_data_path, &img_width, &img_height);
	img_wall = mlx_xpm_file_to_image(mlx_ptr, xpm_data_wall, &img_width, &img_height);
	img_player = mlx_xpm_file_to_image(mlx_ptr, xpm_data_player, &img_width, &img_height);
	img_door = mlx_xpm_file_to_image(mlx_ptr, xpm_data_door, &img_width, &img_height);
	if (img_wall == NULL || img_path == NULL)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
	}
	x = 0;
	y = 0;
	int tab[6][10] = {{1,1,1,1,1,1,1,1,1,1},{1,0,3,0,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1}
					,{1,0,0,0,1,0,0,0,0,1},{1,0,0,0,0,0,0,0,4,1},{1,1,1,1,1,1,1,1,1,1}};
	int row = 0;
	int col = 0;
	while (row < MAX_ROW)
	{
		col = 0;
		x = 0;
		while (col < MAX_COLUMN)
		{
			if (tab[row][col] == 1)
				mlx_put_image_to_window(mlx_ptr, mlx_win, img_wall, x, y);
			else if (tab[row][col] == 0)
				mlx_put_image_to_window(mlx_ptr, mlx_win, img_path, x, y);
			else if (tab[row][col] == 3)
				mlx_put_image_to_window(mlx_ptr, mlx_win, img_player, x, y);
			else
				mlx_put_image_to_window(mlx_ptr, mlx_win, img_door, x, y);
			x += 16;
			++col;
		}
		y += 16;
		++row;
	}

	mlx_loop(mlx_ptr);	

}