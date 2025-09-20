/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvorley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:50:21 by cvorley           #+#    #+#             */
/*   Updated: 2025/09/20 13:20:29 by cvorley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_solution(int *chessboard)
{
	int	i;
	
	i = 0;
	while (i < 10)
		ft_putchar(chessboard[i++] + '0');
	ft_putchar('\n');
}

int	ft_cant_attack(int *chessboard, int p)
{
	int	i;
	
	i = 0;
	while (i < p)
	{
		if (chessboard[i] == chessboard[p] && i != p)
			return (1);
		if (i != p)
		{
			if (chessboard[i] == chessboard[p] - (p - i)
				|| chessboard[i] == chessboard[p] + (p - i))
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_ten_queens_recursive(int chessboard[], int p, int *solutions)
{
	int	i;

	i = 0;
	if (p == 10)
	{
		ft_print_solution(chessboard);
		(*solutions)++;
	}
	else
	{
		while (i <= 9)
		{
			chessboard[p] = i;
			if (!ft_cant_attack(chessboard, p))
				ft_ten_queens_recursive(chessboard, p + 1, solutions);
			i++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	chessboard[10];
	int	solutions;

	solutions = 0;
	ft_ten_queens_recursive(chessboard, 0, &solutions);
	return (solutions);
}

int	main(void)
{
	printf("%d", ft_ten_queens_puzzle());
}
