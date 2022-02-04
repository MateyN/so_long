#include "../includes/so_long.h"

int	check_exit(char move, t_map *map)
{
	if (move == 'E' && map->num_collectable)
		return (0);
	return (1);
}

char	return_next_move(int direction, t_map *map)
{
	if (direction == 0)
		return (map->map[map->pos_player_y - 1][map->pos_player_x]);
	else if (direction == 1)
		return (map->map[map->pos_player_y][map->pos_player_x - 1]);
	else if (direction == 2)
		return (map->map[map->pos_player_y + 1][map->pos_player_x]);
	else if (direction == 3)
		return (map->map[map->pos_player_y][map->pos_player_x + 1]);
	return (-1);
}

void	move_player(int direction, t_map *map)
{
	char	next_move;

	next_move = return_next_move(direction, map);
	if (next_move == 'C')
		map->num_collectable--;
	update_map(direction, next_move, map);
	if (next_move == 'E' && map->num_collectable == 0)
		exit_game(map);
	if (next_move != '1' && next_move != 'E')
	{
		map->moves++;
		ft_putnbr_fd(map->moves, 1);
		write(1, "\n", 1);
	}
	render_map(map);
}

int	move(int keycode, t_map *map)
{
	if (keycode == 13)
		move_player(0, map);
	if (keycode == 0)
		move_player(1, map);
	if (keycode == 1)
		move_player(2, map);
	if (keycode == 2)
		move_player(3, map);
	if (keycode == 53)
		exit_game(map);
	return (0);
}