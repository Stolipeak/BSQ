/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsifess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:43:56 by chsifess          #+#    #+#             */
/*   Updated: 2025/08/27 21:45:06 by chsifess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	initialize_dp(int rows, int cols, int ***dp)
{
	int	i;

	*dp = malloc(sizeof(int *) * rows);
	if (!*dp)
		return ;
	i = 0;
	while (i < rows)
	{
		(*dp)[i] = malloc(sizeof(int) * cols);
		i++;
	}
}
