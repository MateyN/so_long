#include "so_long.h"

static int	check_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_char(char c, t_game *game)
{
	if (c != '1' && c != '0' && c != 'E' && c != 'P' && c != 'C')
		return (0);
	if (c == 'P')
		game->player.count += 1;
	if (c == 'C')
		game->collectible.count += 1;
	if (c == 'E')
		game->exit.count += 1;
	return (1);
}

void	check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.column)
		{
			if (!check_char(game->map.draw[i][j], game))
				exit_error(2, game);
			j++;
		}
		if (game->map.draw[i][0] != '1' || game->map.draw[i][j - 1] != '1')
			exit_error(2, game);
		i++;
	}
	if (!check_wall(game->map.draw[0])
		|| !check_wall(game->map.draw[i - 1]))
		exit_error(2, game);
	if (game->player.count != 1 || game->collectible.count < 1
		|| game->exit.count < 1)
		exit_error(2, game);
}