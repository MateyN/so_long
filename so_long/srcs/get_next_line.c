#include "../includes/so_long.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_return_line(char **buff)
{
	char	*line;
	char	*temp;
	int		i;

	if (!*buff || **buff == '\0')
	{
		free (*buff);
		*buff = NULL;
		return (NULL);
	}
	i = 0;
	while ((*buff)[i] != '\n' && (*buff)[i] != 0)
		i++;
	if ((*buff)[i] == '\n')
		i++;
	line = ft_substr(*buff, 0, i);
	temp = ft_substr(*buff, i, ft_strlen(*buff));
	free(*buff);
	*buff = temp;
	return (line);
}

void	ft_read_file(int fd, char **save)
{
	int		res;
	char	buff[BUFFER_SIZE + 1];
	char	*temp;

	if (BUFFER_SIZE < 0 || BUFFER_SIZE > 1024)
		return ;
	res = read(fd, buff, BUFFER_SIZE);
	while (res > 0)
	{
		buff[res] = '\0';
		if (!*save)
			temp = ft_strdup(buff);
		else
			temp = ft_strjoin(*save, buff);
		free (*save);
		*save = temp;
		if (ft_strchr(*save, '\n'))
			return ;
		res = read(fd, buff, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*line;

	if (BUFFER_SIZE < 0 || fd < 0 || BUFFER_SIZE > 1024)
		return (NULL);
	if (!buff || !(ft_strchr(buff, '\n')))
		ft_read_file(fd, &buff);
	line = ft_return_line(&buff);
	return (line);
}