#include "../includes/so_long.h"

void	read_map(t_map *map, int lines, char *file)
{
	int	fd;
	int	i;

	map->map = 0;
	map->map = malloc(sizeof(char *) * (lines + 1));
	map->map[lines] = 0;
	i = 0;
	while (i < lines)
	{
		map->map[i] = 0;
		i++;
	}
	i = 0;
	fd = open(file, O_RDONLY);
	while (i < lines)
	{
		map->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	count_lines(char *file)
{
	int		fd;
	int		lines;
	int		res;
	char	buff[1];

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\nCan't open the file!\n", 28);
		exit(0);
	}
	lines = 0;
	res = read(fd, buff, 1);
	if (res < 1)
	{
		write(1, "Error\nCan't read the file!\n", 28);
		exit(0);
	}
	while (res > 0)
	{
		if (*buff == '\n')
			lines++;
		res= read(fd, buff, 1);
	}
	return (lines + 1);
}

int	check_ber(char *str)
{
	int	l;

	l = ft_strlen(str);
	if (str[l - 1] != 'r' || str[l - 2] != 'e'
		|| str[l - 3] != 'b' || str[l - 4] != '.')
		return (0);
	return (1);
}

void	parse_map(int argc, char *file, t_map *map)
{
	int	lines;

	if (argc != 2)
	{
		write(1, "Error\nWrong arguments!\n", 24);
		exit(0);
	}
	if (!check_ber(file))
	{
		write(1, "Error\nWrong map extension\n", 27);
		exit(0);
	}
	lines = count_lines(file);
	read_map(map, lines, file);
	map->num_collectable = 0;
	map->moves = 0;
	map->height = lines * 64;
	if (!check_map(map))
	{
		write(1, "Error\nInvalid map.\n", 20);
		free_map(map);
		exit(0);
	}
	map->width = (ft_strlen(map->map[0]) - 1) * 64;
}