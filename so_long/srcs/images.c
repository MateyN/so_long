#include "so_long.h"

static void	player_img(t_game *game)
{
	int	width;
	int	height;

	game->player.img_right = mlx_xpm_file_to_image(game->mlx,
			"assets/player_right.xpm", &width, &height);
	game->player.img_left = mlx_xpm_file_to_image(game->mlx,
			"assets/player_left.xpm", &width, &height);
}

static void	exit_img(t_game	*game)
{
	int	width;
	int	height;

	game->exit.img_c = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm",
			&width, &height);
	game->exit.img_n_c = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm",
			&width, &height);
}

void	get_assets(t_game *game)
{
	int	width;
	int	height;

	player_img(game);
	exit_img(game);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm",
			&width, &height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm",
			&width, &height);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm",
			&width, &height);
}