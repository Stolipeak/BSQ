#include "bsq.h"

char	*read_line(int fd)
{
	char	buffer[1];
	char	*line;
	int		i;
	int		size;

	size = 128;
	line = malloc(size);
	if (!line)
		return (NULL);
	i = 0;
	while (read(fd, buffer, 1) > 0 && buffer[0] != '\n')
	{
		if (i >= size - 1)
		{
			size *= 2;
			line = realloc(line, size);
			if (!line)
				return (NULL);
		}
		line[i++] = buffer[0];
	}
	line[i] = '\0';
	return (line);
}

int	read_first_line(int fd, t_map *map)
{
	char	*first_line;
	int		i;

	first_line = read_line(fd);
	if (!first_line)
		return (0);
	i = 0;
	while (first_line[i] && first_line[i] >= '0' && first_line[i] <= '9')
		i++;
	if (i == 0 || !first_line[i] || !first_line[i + 1] || !first_line[i + 2])
	{
		free(first_line);
		return (0);
	}
	map->rows = ft_atoi(first_line);
	map->empty = first_line[i];
	map->obstacle = first_line[i + 1];
	map->full = first_line[i + 2];
	free(first_line);
	return (map->rows > 0);
}

int	read_grid(int fd, t_map *map)
{
	int		i;
	char	*line;

	map->grid = malloc(sizeof(char *) * map->rows);
	if (!map->grid)
		return (0);
	i = 0;
	while (i < map->rows)
	{
		line = read_line(fd);
		if (!line)
			return (0);
		if (i == 0)
			map->cols = strlen(line);
		else if (strlen(line) != map->cols)
		{
			free(line);
			return (0);
		}
		map->grid[i] = line;
		i++;
	}
	return (1);
}

t_map	*parse_map(int fd)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->rows = 0;
	map->cols = 0;
	map->grid = NULL;
	map->dp = NULL;
	if (!read_first_line(fd, map))
	{
		free(map);
		return (NULL);
	}
	if (!read_grid(fd, map))
	{
		free(map);
		return (NULL);
	}
	return (map);
}