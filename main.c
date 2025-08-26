#include "bsq.h"

void	process_file(char *filename)
{
	int		fd;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	map = parse_map(fd);
	close(fd);
	if (map && is_valid_map(map))
	{
		solve_map(map);
		print_map(map);
	}
	else
		write(2, "map error\n", 10);
	free_map(map);
}

void	process_stdin(void)
{
	t_map	*map;

	map = parse_map(0);
	if (map && is_valid_map(map))
	{
		solve_map(map);
		print_map(map);
	}
	else
		write(2, "map error\n", 10);
	free_map(map);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		process_stdin();
	else
	{
		i = 1;
		while (i < argc)
		{
			process_file(argv[i]);
			if (i < argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}