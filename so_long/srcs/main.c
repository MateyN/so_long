#include "../includes/so_long.h"

int	exit_game(t_map *map)
{
	free_map(map);
	mlx_destroy_window(map->mlx.mlx, map->mlx.win);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	parse_map(ac, av[1], &map);
	map.mlx.mlx = mlx_init();
	map.mlx.win = mlx_new_window(map.mlx.mlx, map.width, map.height, "Mario the Bitcoin digger!");
	draw_images(&map);
	render_map(&map);
	mlx_hook(map.mlx.win, 2, 1L << 0, move, &map);
	mlx_hook(map.mlx.win, 17, 0L, exit_game, &map);
	mlx_loop(map.mlx.mlx);
}