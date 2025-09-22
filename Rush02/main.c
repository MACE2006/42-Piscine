/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmarsha <evmarsha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:16:41 by evmarsha          #+#    #+#             */
/*   Updated: 2025/09/21 21:16:43 by evmarsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_three_word(char *my_buff, char *str);

void	main_helper(char *my_buff, int argc, char *argv[], char *nbr_str)
{
	if (argc == 2 || argc == 3)
	{
		if (argc == 2)
		{
			nbr_str = argv[1];
			my_buff = read_file("numbers.dict");
		}
		else if (argc == 3)
		{
			nbr_str = argv[2];
			my_buff = read_file(argv[1]);
		}
		nbr_str = ft_atoi(nbr_str);
		if (nbr_str != NULL)
		{
			nbr_str = make_nbr_str(nbr_str);
			make_substr(my_buff, nbr_str);
			free(nbr_str);
		}
		else
			write(1, "Error\n", 6);
		free(my_buff);
	}
	else
		write(1, "Error\n", 6);
}

int	main(int argc, char *argv[])
{
	char	*my_buff;
	char	*nbr_str;

	my_buff = NULL;
	nbr_str = NULL;
	main_helper(my_buff, argc, argv, nbr_str);
	return (0);
}
