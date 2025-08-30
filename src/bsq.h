/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsifess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:15:48 by chsifess          #+#    #+#             */
/*   Updated: 2025/08/27 23:12:24 by chsifess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_grid_params
{
	int		rows;
	int		cols;
	char	**grid;
	char	*chars;
}	t_grid_params;

typedef struct s_solution
{
	int	size;
	int	i;
	int	j;
}	t_solution;

int		process_file(char *filename);
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
void	*ft_realloc(void *ptr, int old_size, int new_size);
int		min(int a, int b, int c);
void	initialize_dp(int rows, int cols, int ***dp);
void	fill_dp_grid(t_grid_params params, int **dp);

#endif
