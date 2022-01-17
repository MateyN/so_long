#include "so_long.h"

void	put_player(t_game *game, int i, int j)
{
	game->player.row = i;
	game->player.column = j;
	if (!game->player.position)
		mlx_put_image_to_window(game->mlx, game->win, game->player.img_left,
			j * HEIGHT, i * WIDTH);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->player.img_right,
			j * HEIGHT, i * WIDTH);
}

void	put_exit(t_game *game, int i, int j)
{
	if (game->collectible.count)
		mlx_put_image_to_window(game->mlx, game->win, game->exit.img_c,
			j * HEIGHT, i * WIDTH);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->exit.img_n_c,
			j * HEIGHT, i * WIDTH);
}

void	check_render(t_game *game, int i, int j)
{
	if (game->map.draw[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
			j * HEIGHT, i * WIDTH);
	if (game->map.draw[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img,
			j * HEIGHT, i * WIDTH);
	if (game->map.draw[i][j] == 'P')
		put_player(game, i, j);
	if (game->map.draw[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectible.img,
			j * HEIGHT, i * WIDTH);
	if (game->map.draw[i][j] == 'E')
		put_exit(game, i, j);
}

void	ft_game(t_game *game)
{
	int	i;
	int	j;

	mlx_clear_window(game->mlx, game->win);
	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.column)
		{
			check_render(game, i, j);
			j++;
		}
		i++;
	}
}