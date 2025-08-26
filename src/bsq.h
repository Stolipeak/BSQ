#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	process_file(char *filename);
void	process_stdin(void);
void	solve_bsq(int rows, int cols, char **grid, char chars[3]);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
char	*read_line(int fd);
int		parse_first_line(int fd, int *rows, char chars[3]);
char	**parse_grid(int fd, int rows, int *cols);
int		is_valid_grid(char **grid, int rows, int cols, char chars[3]);
void	free_grid(char **grid, int rows);
void	print_grid(char **grid, int rows, int cols);

#endif