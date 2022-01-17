#include "so_long.h"

static void	destroy_images(t_game *game)
{
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->exit.img_c)
		mlx_destroy_image(game->mlx, game->exit.img_c);
	if (game->exit.img_n_c)
		mlx_destroy_image(game->mlx, game->exit.img_n_c);
	if (game->collectible.img)
		mlx_destroy_image(game->mlx, game->collectible.img);
	if (game->player.img_right)
		mlx_destroy_image(game->mlx, game->player.img_right);
	if (game->player.img_left)
		mlx_destroy_image(game->mlx, game->player.img_left);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
}

static void	ft_free(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.row)
	{
		if (game->map.draw[i])
			free(game->map.draw[i]);
		i++;
	}
	if (game->map.draw)
		free(game->map.draw);
}

int	destroy_notify(t_game *game)
{
	exit_error(6, game);
	return (0);
}

void	exit_error(int error, t_game *game)
{
	if (error == 0)
		printf("Argument Error!\n");
	if (error == 1)
		printf("File Error!\n");
	if (error == 2)
		printf("Map Error!\n");
	if (error == 3)
		printf("Assets Error!\n");
	if (error == 4)
		printf("Malloc Error!\n");
	if (error == 5)
		printf("\nYou win!\n");
	if (error == 6)
		printf("\nQuit successfully!\n" );
	ft_free(game);
	destroy_images(game);
	exit(0);
}