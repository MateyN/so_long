#include "so_long.h"

void	move_right(t_game *game, int *count)
{
	int	prow;
	int	pcol;

	prow = game->player.row;
	pcol = game->player.column;
	if (game->map.draw[prow][pcol + 1] == 'E')
	{
		if (game->collectible.count == 0)
			exit_error(5, game);
		return ;
	}
	game->player.position = 1;
	*count = 1;
	game->map.draw[prow][pcol] = '0';
	pcol += 1;
	if (game->map.draw[prow][pcol] == 'C')
	{
		game->map.draw[prow][pcol] = '0';
		game->collectible.count -= 1;
	}
	game->map.draw[prow][pcol] = 'P';
}

void	move_left(t_game *game, int *count)
{
	int	prow;
	int	pcol;

	prow = game->player.row;
	pcol = game->player.column;
	if (game->map.draw[prow][pcol - 1] == 'E')
	{
		if (game->collectible.count == 0)
			exit_error(5, game);
		return ;
	}
	game->player.position = 0;
	*count = 1;
	game->map.draw[prow][pcol] = '0';
	pcol -= 1;
	if (game->map.draw[prow][pcol] == 'C')
	{
		game->map.draw[prow][pcol] = '0';
		game->collectible.count -= 1;
	}
	game->map.draw [prow][pcol] = 'P';
}

void	move_down(t_game *game, int *count)
{
	int	prow;
	int	pcol;

	prow = game->player.row;
	pcol = game->player.column;
	if (game->map.draw[prow + 1][pcol] == 'E')
	{
		if (game->collectible.count == 0)
			exit_error(5, game);
		return ;
	}
	*count = 1;
	game->map.draw[prow][pcol] = '0';
	prow += 1;
	if (game->map.draw[prow][pcol] == 'C')
	{
		game->map.draw[prow][pcol] = '0';
		game->collectible.count -= 1;
	}
	game->map.draw [prow][pcol] = 'P';
}

void	move_up(t_game *game, int *count)
{
	int	prow;
	int	pcol;

	prow = game->player.row;
	pcol = game->player.column;
	if (game->map.draw[prow - 1][pcol] == 'E')
	{
		if (game->collectible.count == 0)
			exit_error(5, game);
		return ;
	}
	*count = 1;
	game->map.draw[prow][pcol] = '0';
	prow -= 1;
	if (game->map.draw[prow][pcol] == 'C')
	{
		game->map.draw[prow][pcol] = '0';
		game->collectible.count -= 1;
	}
	game->map.draw [prow][pcol] = 'P';
}

int	ft_move(int key, t_game *game)
{
	static int	i = 1;
	int			count;
	int			prow;
	int			pcol;

	count = 0;
	prow = game->player.row;
	pcol = game->player.column;
	if (key == RIGHT && game->map.draw[prow][pcol + 1] != '1')
		move_right(game, &count);
	if (key == LEFT && game->map.draw[prow][pcol - 1] != '1')
		move_left(game, &count);
	if (key == DOWN && game->map.draw[prow + 1][pcol] != '1')
		move_down(game, &count);
	if (key == UP && game->map.draw[prow - 1][pcol] != '1')
		move_up(game, &count);
	if (key == ESC)
		exit_error(6, game);
	if (count)
		printf("Moves: [%d]\n", i++);
	ft_game(game);
	return (1);
}
