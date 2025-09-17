/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvorley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:04:05 by cvorley           #+#    #+#             */
/*   Updated: 2025/09/05 10:31:25 by cvorley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int	i[2];

	i[0] = 0;
	while (i[0] < 99)
	{
		i[1] = i[0] + 1;
		while (i[1] < 100)
		{
			write_number(i[0]);
			write(1, " ", 1);
			write_number(i[1]);
			if (i[0] == 98 && i[1] == 99)
				write(1, ".\n", 2);
			else
				write(1, ", ", 2);
			i[1]++;			
		}
		i[0]++;
	}
}

void	write_number(int n)
{
	char c;

	if (n < 10)
	{
		c = n + 48;
		write(1, "0", 1);
		write(1, &c, 1);
		return ;
	}
	c = (n / 10) + 48;
	write(1, &c, 1);
	c = n % 10 + 48;
	write(1, &c, 1);
}

/*int	main(void)
{
	ft_print_comb2();
}*/
