/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihu <jihu@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:37:31 by jihu              #+#    #+#             */
/*   Updated: 2025/09/24 15:00:55 by jihu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		i;

	if (argc < 2)
	{
		map = ft_create_map("STDIN");
		if (map)
		{
			ft_process_map(map);
		}
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		map = ft_create_map(argv[i]);
		if (map)
			ft_process_map(map);
		i++;
		if (i < argc)
			write(1, "\n", 1);
	}
	return (0);
}
