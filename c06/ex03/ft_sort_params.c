/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvorley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:32:58 by cvorley           #+#    #+#             */
/*   Updated: 2025/09/20 10:12:39 by cvorley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s2;
	*s2 = *s1;
	*s1 = tmp;
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc >= 2)
	{
		while (++i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i+1]) > 0)
			{
				swap(&argv[i], &argv[i + 1]);
				i = 0;
			}
		}
		i = 0;
		while (++i < argc)
		{
			ft_putstr(argv[i]);
			ft_putchar('\n');
		}
	}
	return (0);
}
