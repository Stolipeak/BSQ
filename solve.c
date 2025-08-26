#include "bsq.h"

int	min(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void	init_dp(t_map *map)
{
	int	i;
	int	j;

	map->dp = malloc(sizeof(int *) * map->rows);
	if (!map->dp)
		return ;
	i = 0;
	while (i < map->rows)
	{
		map->dp[i] = malloc(sizeof(int) * map->cols);
		if (!map->dp[i])
			return ;
		j = 0;
		while (j < map->cols)
		{
			if (map->grid[i][j] == map->obstacle)
				map->dp[i][j] = 0;
			else
				map->dp[i][j] = 1;
			j++;
		}
		i++;
	}
}

void	find_largest_square(t_map *map, int *max_i, int *max_j, int *max_size)
{
	int	i;
	int	j;

	*max_size = 0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->grid[i][j] != map->obstacle)
			{
				if (i > 0 && j > 0)
					map->dp[i][j] = 1 + min(map->dp[i-1][j],
											map->dp[i][j-1],
											map->dp[i-1][j-1]);
				if (map->dp[i][j] > *max_size)
				{
					*max_size = map->dp[i][j];
					*max_i = i;
					*max_j = j;
				}
			}
			j++;
		}
		i++;
	}
}

void	fill_square(t_map *map, int max_i, int max_j, int max_size)
{
	int	i;
	int	j;

	i = max_i - max_size + 1;
	while (i <= max_i)
	{
		j = max_j - max_size + 1;
		while (j <= max_j)
		{
			map->grid[i][j] = map->full;
			j++;
		}
		i++;
	}
}

void	solve_map(t_map *map)
{
	int	max_i;
	int	max_j;
	int	max_size;

	init_dp(map);
	if (!map->dp)
		return ;
	find_largest_square(map, &max_i, &max_j, &max_size);
	if (max_size > 0)
		fill_square(map, max_i, max_j, max_size);
}