#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"

/*--------- STRUCTS ---------*/

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	            t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	            t_mlx;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		img_width;
	int		img_height;
	t_mlx	mlx;
	t_data	grass;
	t_data	wall;
	t_data	player;
	t_data	collectable;
	t_data	exit;
	int		num_collectable;
	int		pos_player_x;
	int		pos_player_y;
	int		moves;
}	            t_map;

/*--------- MAP FUNCTIONS ---------*/
void	render_map(t_map *map);
void	update_map(int direction, char next_move, t_map *map);
void	free_map(t_map *map);

/*--------- DRAW_MAP FUNCTIONS ---------*/
void	draw_window(t_map *map, int x, int y);
void	draw_images(t_map *map);

/*--------- CHECK_MAP FUNCTIONS ---------*/
int		check_map(t_map *map);
int		check_strlen(t_map *map, int max);
int		check_top_bottom(t_map *map, int max);
int		check_sides(t_map *map, int max, int wall_1);
int		check_items(t_map *map, int wall_1, int exit, int player);

/*--------- UTILS FUNCTIONS ---------*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*--------- MOVEMENTS FUNCTIONS ---------*/
int		check_exit(char move, t_map *map);
char	return_next_move(int dir, t_map *map);
void	move_player(int direction, t_map *map);
int		move(int keycode, t_map *map);

/*--------- READ_PARSE_MAP FUNCTIONS ---------*/
void	parse_map(int argc, char *file, t_map *map);
int		count_lines(char *file);
void	read_map(t_map *map, int lines, char *file);

/*--------- MAIN ---------*/
int		exit_game(t_map *map);

#endif