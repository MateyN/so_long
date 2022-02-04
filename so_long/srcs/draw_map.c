#include "../includes/so_long.h"

void	draw_images(t_map *map)
{
	char	*ground;
	char	*wall;
	char	*player;
	char	*collectable;
	char	*exit;

	ground = "assets/grass64x64.xpm";
	wall = "assets/wall64x64.xpm";
	player = "assets/mario64x64.xpm";
	collectable = "assets/bitcoin64x64.xpm";
	exit = "assets/peach64x64.xpm";
	map->grass.img = mlx_xpm_file_to_image
		(map->mlx.mlx, ground, &map->img_width, &map->img_height);
	map->wall.img = mlx_xpm_file_to_image
		(map->mlx.mlx, wall, &map->img_width, &map->img_height);
	map->player.img = mlx_xpm_file_to_image
		(map->mlx.mlx, player, &map->img_width, &map->img_height);
	map->collectable.img = mlx_xpm_file_to_image
		(map->mlx.mlx, collectable, &map->img_width, &map->img_height);
	map->exit.img = mlx_xpm_file_to_image
		(map->mlx.mlx, exit, &map->img_width, &map->img_height);
}

void	draw_window(t_map *map, int x, int y)
{
	if (map->map[y][x] == '0')
		mlx_put_image_to_window
			(map->mlx.mlx, map->mlx.win, map->grass.img, x * 64, y * 64);
	if (map->map[y][x] == '1')
		mlx_put_image_to_window
			(map->mlx.mlx, map->mlx.win, map->wall.img, x * 64, y * 64);
	if (map->map[y][x] == 'C')
		mlx_put_image_to_window
			(map->mlx.mlx, map->mlx.win, map->collectable.img, x * 64, y * 64);
	if (map->map[y][x] == 'E')
		mlx_put_image_to_window
			(map->mlx.mlx, map->mlx.win, map->exit.img, x * 64, y * 64);
	if (map->map[y][x] == 'P')
	{
		mlx_put_image_to_window
			(map->mlx.mlx, map->mlx.win, map->player.img, x * 64, y * 64);
		map->pos_player_y = y;
		map->pos_player_x = x;
	}
}