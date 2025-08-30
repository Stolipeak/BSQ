/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: chsifess <marvin@42.fr>                    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/08/27 21:30:55 by chsifess          #+#    #+#             */
/*   Updated: 2025/08/27 21:34:55 by chsifess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	fill_dp_grid(t_grid_params params, int **dp)
{
	int	i;
	int	j;

	i = 0;
	while (i < params.rows)
	{
		j = 0;
		while (j < params.cols)
		{
			if (params.grid[i][j] == params.chars[1])
				dp[i][j] = 0;
			else
			{
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j
							- 1]);
			}
			j++;
		}
		i++;
	}
}

void	find_max_square(int rows, int cols, int **dp, int max[3])
{
	int	i;
	int	j;

	max[0] = 0;
	max[1] = 0;
	max[2] = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (dp[i][j] > max[0])
			{
				max[0] = dp[i][j];
				max[1] = i;
				max[2] = j;
			}
			j++;
		}
		i++;
	}
}

void	fill_solution(t_solution sol, char **grid, char fill_char)
{
	int	i;
	int	j;

	i = sol.i - sol.size + 1;
	while (i <= sol.i)
	{
		j = sol.j - sol.size + 1;
		while (j <= sol.j)
		{
			grid[i][j] = fill_char;
			j++;
		}
		i++;
	}
}

void	free_dp(int rows, int **dp)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}

void	solve_bsq(int rows, int cols, char **grid, char chars[3])
{
	int				**dp;
	int				max[3];
	t_solution		sol;
	t_grid_params	params;

	params.rows = rows;
	params.cols = cols;
	params.grid = grid;
	params.chars = chars;
	initialize_dp(rows, cols, &dp);
	if (!dp)
		return ;
	fill_dp_grid(params, dp);
	find_max_square(rows, cols, dp, max);
	if (max[0] > 0)
	{
		sol.size = max[0];
		sol.i = max[1];
		sol.j = max[2];
		fill_solution(sol, grid, chars[2]);
	}
	free_dp(rows, dp);
}
