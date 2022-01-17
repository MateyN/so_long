#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	start_game(&game);
	if (argc != 2)
		exit_error(0, &game);
	generate_map(argv[1], &game);
	check_map(&game);
	generate_game(&game);
	get_assets(&game);
	ft_game(&game);
	mlx_hook(game.win, 2, 2L << 0, ft_move, &game);
	mlx_hook(game.win, 17, 0L, destroy_notify, &game);
	mlx_loop(game.mlx);
	return (0);
}
