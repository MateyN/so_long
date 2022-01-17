#include "so_long.h"

void	start_game(t_game *game)
{
	game->map.draw = ft_calloc(1, sizeof(char *));
	if (!game->map.draw)
		exit_error(4, game);
	game->map.row = 0;
	game->map.column = 0;
	game->player.img_right = NULL;
	game->player.img_left = NULL;
	game->player.count = 0;
	game->player.row = 0;
	game->player.column = 0;
	game->player.position = 0;
	game->collectible.img = NULL;
	game->collectible.count = 0;
	game->exit.img_c = NULL;
	game->exit.img_n_c = NULL;
	game->exit.count = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->floor_img = NULL;
	game->wall_img = NULL;
}

void	generate_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
		exit_error(6, game);
	game->win = mlx_new_window(game->mlx, HEIGHT * game->map.column, \
	WIDTH * game->map.row, "so_long");
}