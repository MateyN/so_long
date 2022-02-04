#include "../includes/so_long.h"

int	check_strlen(t_map *map, int max)
{
	int		i;
	size_t	len;

	len = ft_strlen(map->map[0]);
	i = 0;
	while (i < max)
	{
		if (len != ft_strlen(map->map[i]))
			return (0);
		i++;
	}
	if (len != ft_strlen(map->map[i]) + 1)
		return (0);
	return (1);
}

int	check_top_bottom(t_map *map, int max)
{
	int	i;

	i = 0;
	while (map->map[0][i] != '\n')
	{
		if (map->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map->map[max][i])
	{
		if (map->map[max][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_sides(t_map *map, int max, int wall_1)
{
	int	i;

	i = 1;
	while (i < max)
	{
		if (map->map[i][0] != '1' || map->map[i][wall_1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_items(t_map *map, int wall_1, int exit, int player)
{
	int	i;
	int	j;

	i = 1;
	while (i < (map->height / 64) - 1)
	{
		j = 1;
		while (j < wall_1)
		{
			if (map->map[i][j] == 'P')
				player++;
			else if (map->map[i][j] == 'C')
				map->num_collectable++;
			else if (map->map[i][j] == 'E')
				exit++;
			else if (map->map[i][j] != '0' && map->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	if (player != 1 || exit != 1 || !map->num_collectable)
		return (0);
	return (1);
}

int	check_map(t_map *map)
{
	int	wall_1;
	int	player;
	int	exit;
	int	max;

	max = (map->height / 64) - 1;
	if (!check_strlen(map, max))
		return (0);
	if (!check_top_bottom(map, max))
		return (0);
	wall_1 = ft_strlen(map->map[0]) - 2;
	if (!check_sides(map, max, wall_1))
		return (0);
	map->num_collectable = 0;
	player = 0;
	exit = 0;
	if (!check_items(map, wall_1, exit, player))
		return (0);
	if (max == wall_1)
		return (0);
	return (1);
}