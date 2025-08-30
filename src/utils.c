/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsifess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:24:21 by chsifess          #+#    #+#             */
/*   Updated: 2025/08/27 21:25:20 by chsifess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_atoi(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*ft_realloc(void *ptr, int old_size, int new_size)
{
	void	*new_ptr;
	int		copy_size;
	int		i;

	if (new_size == 0)
	{
		return (free(ptr), NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
	{
		return (free(ptr), NULL);
	}
	if (ptr)
	{
		if (old_size < new_size)
			copy_size = old_size;
		else
			copy_size = new_size;
		i = -1;
		while (++i < copy_size)
			((char *)new_ptr)[i] = ((char *)ptr)[i];
		free(ptr);
	}
	return (new_ptr);
}

void	free_grid(char **grid, int rows)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (i < rows)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	print_grid(char **grid, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		write(1, grid[i], cols);
		write(1, "\n", 1);
		i++;
	}
}
