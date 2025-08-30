/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsifess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:18:22 by chsifess          #+#    #+#             */
/*   Updated: 2025/08/27 21:40:31 by chsifess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			line = ft_realloc(line, i, size);
			if (!line)
				return (NULL);
		}
		line[i++] = buffer[0];
	}
	line[i] = '\0';
	return (line);
}

int	parse_first_line(int fd, int *rows, char chars[3])
{
	char	*first_line;
	int		i;

	first_line = read_line(fd);
	if (!first_line)
		return (0);
	if (ft_strlen(first_line) < 4)
		return (free(first_line), 0);
	i = 0;
	while (first_line[i] && first_line[i] >= '0' && first_line[i] <= '9')
		i++;
	if (i == 0 || (ft_strlen(first_line) - i) != 3)
	{
		return (free(first_line), 0);
	}
	*rows = ft_atoi(first_line);
	chars[0] = first_line[i];
	chars[1] = first_line[i + 1];
	chars[2] = first_line[i + 2];
	free(first_line);
	return (*rows > 0);
}

char	**parse_grid(int fd, int rows, int *cols)
{
	char	**grid;
	char	*line;
	int		i;

	grid = malloc(sizeof(char *) * rows);
	if (!grid)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		line = read_line(fd);
		if (!line)
			return (free_grid(grid, i), NULL);
		if (i == 0)
			*cols = ft_strlen(line);
		else if (ft_strlen(line) != *cols)
			return (free(line), free_grid(grid, i), NULL);
		grid[i] = line;
		i++;
	}
	return (grid);
}

int	is_valid_grid(char **grid, int rows, int cols, char chars[3])
{
	int	i;
	int	j;

	if (chars[0] == chars[1] || chars[0] == chars[2] || chars[1] == chars[2])
		return (0);
	if (rows <= 0 || cols <= 0)
		return (0);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (grid[i][j] != chars[0] && grid[i][j] != chars[1])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
