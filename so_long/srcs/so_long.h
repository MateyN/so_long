#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "srcs/get_next_line.h"

# define HEIGHT 32
# define WIDTH 32
//---------------------------------------------
// KEYCODE MOVEMENT
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
//---------------------------------------------
// MAP STRUCT
typedef struct map
{
	char	**draw;
	int		column;
	int		row;
}			t_map;
//---------------------------------------------
// PLAYER STRUCT
typedef struct s_player
{
	void	*img_right;
	void	*img_left;
	int		count;
	int		row;
	int		column;
	int		position;
}				t_player;
//---------------------------------------------
// IMAGES STRUCT
typedef struct s_image
{
	void	*img;
	int		count;
}				t_image;

typedef struct s_exit
{
	void	*img_c;
	void	*img_n_c;
	int		count;
}				t_exit;
//---------------------------------------------
// MAIN GAME STRUCT
typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_image		collectible;
	t_exit		exit;
	void		*floor_img;
	void		*wall_img;
}				t_game;
//---------------------------------------------
// FUNCTIONS
void	start_game(t_game *game);
void	generate_map(char *file, t_game *game);
void	check_map(t_game *game);
void	generate_game(t_game *game);
void	get_assets(t_game *game);
void	ft_game(t_game *game);
int		ft_move(int key, t_game *game);
void	exit_error(int error, t_game *game);
int		destroy_notify(t_game *game);

#endif
