/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvorley <cvorley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:24:08 by cvorley           #+#    #+#             */
/*   Updated: 2025/09/24 16:54:35 by cvorley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if (map->mx[i])
		{
			free(map->mx[i++]);
		}
		else
			break ;
	}
	free(map->mx);
	free(map);
}

static int	ft_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

void	ft_get_square(t_map *map)
{
	register int	row;
	register int	col;

	row = map->rows - 1;
	while (row >= 0)
	{
		col = map->c - 1;
		while (col >= 0)
		{
			if (map->mx[row][col])
			{
				if (!(row == map->rows - 1 || col == map->c - 1))
					map->mx[row][col] = ft_min(map->mx[row + 1][col + 1], \
							map->mx[row + 1][col], map->mx[row][col + 1]) + 1;
				if (map->mx[row][col] >= map->square_size)
				{
					map->square_size = map->mx[row][col];
					map->square_row = row;
					map->square_col = col;
				}
			}
			col--;
		}
		row--;
	}
}

static void	ft_print_solution(t_map *map, int s_square_row, int s_sqaure_col)
{
	register int	finish_square_row;
	register int	finish_square_col;
	register int	i;
	register int	j;

	finish_square_row = s_square_row + map->square_size - 1;
	finish_square_col = s_sqaure_col + map->square_size - 1;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->c)
		{
			if (!(map->mx[i][j]))
				write(1, &(map->obstacle), 1);
			else if (i >= s_square_row && i <= finish_square_row && \
					j >= s_sqaure_col && j <= finish_square_col)
				write(1, &(map->full), 1);
			else
				write(1, &(map->empty), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_process_map(t_map *map)
{
	int	start_square_row;
	int	start_square_col;

	ft_get_square(map);
	start_square_col = map->square_col;
	start_square_row = map->square_row;
	ft_print_solution(map, start_square_row, start_square_col);
	ft_free_map(map);
}
