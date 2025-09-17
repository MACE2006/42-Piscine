/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvorley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:19:31 by cvorley           #+#    #+#             */
/*   Updated: 2025/09/08 08:46:18 by cvorley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*Declaring varaibles and counting in while loops for each value. 
 * Calls the writer function and adds them to the char*/
void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a <= 9)
	{
		b = a + 1;
		while (b <= 9)
		{
			c = b + 1;
			while (c <= 9)
			{
				writer(a + '0', b + '0', c + '0');
				c++;
			}
			b++;
		}
		a++;
	}
}
/*Writes the values in the terminal and adds the spaces. 
 * Once the value reaches then return.*/

void	writer(char a, char b, char c)
{
	write (1, &a, 1);
	write (1, &b, 1);
	write (1, &c, 1);
	if (a == '7' && b == '8' && c == '9')
		return ;
	write (1, ",", 1);
	write (1, " ", 1);
}

/*int	main(void)
{
	ft_print_comb();
	return (0);
}*/
