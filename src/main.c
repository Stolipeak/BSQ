#include "bsq.h"

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