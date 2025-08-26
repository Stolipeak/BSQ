#include "bsq.h"

int	min(int a, int b, int c)
{
	int	min_val;

	min_val = a;
	if (b < min_val)
		min_val = b;
	if (c < min_val)
		min_val = c;
	return (min_val);
}

void	solve_bsq(int rows, int cols, char **grid, char chars[3])
{
	int	**dp;
	int	i;
	int	j;
	int	max_size;
	int	max_i;
	int	max_j;

	// Allouer le tableau DP
	dp = malloc(sizeof(int *) * rows);
	for (i = 0; i < rows; i++)
		dp[i] = malloc(sizeof(int) * cols);
	
	// Initialiser DP
	max_size = 0;
	max_i = 0;
	max_j = 0;
	
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (grid[i][j] == chars[1]) // Obstacle
				dp[i][j] = 0;
			else
			{
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
				
				if (dp[i][j] > max_size)
				{
					max_size = dp[i][j];
					max_i = i;
					max_j = j;
				}
			}
		}
	}
	
	// Remplir le carré
	if (max_size > 0)
	{
		for (i = max_i - max_size + 1; i <= max_i; i++)
			for (j = max_j - max_size + 1; j <= max_j; j++)
				grid[i][j] = chars[2]; // Caractère plein
	}
	
	// Libérer DP
	for (i = 0; i < rows; i++)
		free(dp[i]);
	free(dp);
}