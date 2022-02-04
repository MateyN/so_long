#include "../includes/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	update_map(int direction, char next_move, t_map *map)
{
	if (direction == 0 && next_move != '1' && check_exit(next_move, map))
	{
		map->map[map->pos_player_y][map->pos_player_x] = '0';
		map->map[map->pos_player_y - 1][map->pos_player_x] = 'P';
		map->pos_player_y--;
	}
	else if (direction == 1 && next_move != '1' && check_exit(next_move, map))
	{
		map->map[map->pos_player_y][map->pos_player_x] = '0';
		map->map[map->pos_player_y][map->pos_player_x - 1] = 'P';
		map->pos_player_x--;
	}
	else if (direction == 2 && next_move != '1' && check_exit(next_move, map))
	{
		map->map[map->pos_player_y][map->pos_player_x] = '0';
		map->map[map->pos_player_y + 1][map->pos_player_x] = 'P';
		map->pos_player_y++;
	}
	else if (direction == 3 && next_move != '1' && check_exit(next_move, map))
	{
		map->map[map->pos_player_y][map->pos_player_x] = '0';
		map->map[map->pos_player_y][map->pos_player_x + 1] = 'P';
		map->pos_player_x++;
	}
}

void	render_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < (map->width) / 64)
	{
		y = 0;
		while (y < (map->height) / 64)
		{
			draw_window(map, x, y);
			y++;
		}
		x++;
	}
}