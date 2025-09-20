/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvorley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:12:01 by cvorley           #+#    #+#             */
/*   Updated: 2025/09/06 15:28:55 by cvorley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print(int columns, char c, char d, char e)
{
	int	i;

	i = 1;
	while (i <= columns)
	{
		if (i == 1)
		{
			ft_putchar(c);
		}
		else if (i == columns)
		{
			ft_putchar(e);
		}
		else
		{
			ft_putchar(d);
		}
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;
	int	column;
	int	row;

	i = 1;
	column = x;
	row = y;
	if (column >= 1 && row >= 1)
	{
		while (i <= row)
		{
			if (i == 1)
				ft_print(column, 'A', 'B', 'C');
			else if (i == row)
			{
				ft_print(column, 'A', 'B', 'C');
			}
			else
			{
				ft_print(column, 'B', ' ', 'B');
			}
			i++;
		}
	}
}
