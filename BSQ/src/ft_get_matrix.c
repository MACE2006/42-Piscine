/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvorley <cvorley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:24:02 by cvorley           #+#    #+#             */
/*   Updated: 2025/09/24 17:09:23 by cvorley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_get_line(t_map *map, int i, int file_name)
{
	int		j;
	int		readl;
	char	buffer;

	j = 0;
	while (1)
	{
		readl = read(file_name, &buffer, 1);
		if (j == map->c)
		{
			if (buffer != '\n')
				return (1);
			else
				return (0);
		}
		if ((buffer != map->empty && buffer != map->obstacle) || readl < 1)
			return (1);
		if (buffer == map->empty)
			map->mx[i][j++] = 1;
		else
			map->mx[i][j++] = 0;
	}
	return (1);
}

int	ft_get_first_line(t_map *map, int file_name)
{
	char	buffer;
	int		i;
	int		readl;

	map->mx[0] = (unsigned short *)malloc(128 * sizeof(unsigned short));
	map->c = 128;
	i = 0;
	while (1)
	{
		readl = read(file_name, &buffer, 1);
		if (buffer == '\n')
			break ;
		if ((buffer != map->empty && buffer != map->obstacle) || readl < 1)
			return (1);
		map->mx[0][i++] = (buffer == map->empty);
		if (i == map->c)
		{
			map->mx[0] = (unsigned short *)ft_realloc(map->mx[0], \
				map->c * sizeof(unsigned short), map->c * 2 * (2));
			map->c *= 2;
		}
	}
	map->mx[0] = (unsigned short *)ft_realloc(map->mx[0], \
		map->c * sizeof(unsigned short), i * sizeof(unsigned short));
	return (!(map->c = i));
}

static void	ft_set_null(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		map->mx[i] = NULL;
		i++;
	}
}

int	ft_get_matrix(t_map *map, int file_name)
{
	int	i;

	map->mx = (unsigned short **)malloc(map->rows * \
		sizeof(unsigned short *));
	ft_set_null(map);
	if (ft_get_first_line(map, file_name))
		return (1);
	i = 1;
	while (i < map->rows)
	{
		map->mx[i] = (unsigned short *)malloc(map->c * \
			sizeof(unsigned short));
		if (ft_get_line(map, i, file_name))
			return (1);
		i++;
	}
	if (read(file_name, &i, 1))
		return (1);
	return (0);
}
