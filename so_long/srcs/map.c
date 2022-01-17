#include "so_long.h"

static void	check_extention(char *file, t_game *game)
{
	int		i;
	int		lenght;
	char	*ber;

	ber = ".ber";
	i = 3;
	lenght = ft_strlen(file) - 1;
	while (i >= 0)
	{
		if (file[lenght] != ber[i])
			exit_error(1, game);
		i--;
		lenght--;
	}
}

static void	check_lenght(char *line, int col, t_game *game)
{
	int	lenght;

	lenght = ft_strlen(line);
	if (ft_strchr(line, '\n'))
		lenght--;
	if (lenght != col)
		exit_error(2, game);
}

static void	fill_map(t_game *game, char *line)
{
	char	**map;
	size_t	i;

	i = 0;
	game->map.row = game->map.row + 1;
	map = malloc(sizeof(char *) * (game->map.row + 1));
	if (!map)
		exit_error(4, game);
	while (game->map.draw[i])
	{
		map[i] = game->map.draw[i];
		i++;
	}
	map[i] = line;
	map[i + 1] = NULL;
	free(game->map.draw);
	game->map.draw = map;
}

void	generate_map(char *file, t_game *game)
{
	int		fd;
	char	*line;

	check_extention(file, game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(1, game);
	line = get_next_line(fd);
	if (!line)
		exit_error(2, game);
	game->map.column = ft_strlen(line) - 1;
	while (line)
	{
		check_lenght(line, game->map.column, game);
		fill_map(game, line);
		line = get_next_line(fd);
	}
	close(fd);
}