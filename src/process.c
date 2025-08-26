#include "bsq.h"

void	process_file(char *filename)
{
	int		fd;
	int		rows;
	int		cols;
	char	chars[3];
	char	**grid;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	
	if (!parse_first_line(fd, &rows, chars))
	{
		close(fd);
		write(2, "map error\n", 10);
		return ;
	}
	
	grid = parse_grid(fd, rows, &cols);
	close(fd);
	
	if (!grid || !is_valid_grid(grid, rows, cols, chars))
	{
		if (grid) free_grid(grid, rows);
		write(2, "map error\n", 10);
		return ;
	}
	
	solve_bsq(rows, cols, grid, chars);
	print_grid(grid, rows, cols);
	free_grid(grid, rows);
}

void	process_stdin(void)
{
	int		rows;
	int		cols;
	char	chars[3];
	char	**grid;

	if (!parse_first_line(0, &rows, chars))
	{
		write(2, "map error\n", 10);
		return ;
	}
	
	grid = parse_grid(0, rows, &cols);
	if (!grid || !is_valid_grid(grid, rows, cols, chars))
	{
		if (grid) free_grid(grid, rows);
		write(2, "map error\n", 10);
		return ;
	}
	
	solve_bsq(rows, cols, grid, chars);
	print_grid(grid, rows, cols);
	free_grid(grid, rows);
}