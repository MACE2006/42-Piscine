/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmarsha <evmarsha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:16:27 by evmarsha          #+#    #+#             */
/*   Updated: 2025/09/21 21:16:30 by evmarsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_aword(char *needle)
{
	int	i;

	i = 0;
	if (needle == NULL)
		write(1, "Dict Error\n", 11);
	else
	{
		while (needle[i] != '\0')
		{
			if ((needle[i] >= 'a' && needle[i] <= 'z') || (needle[i] >= 'A'
					&& needle[i] <= 'Z'))
			{
				ft_putstr(&needle[i]);
				break ;
			}
			if (needle[i + 1] == '\n')
				break ;
			i++;
		}
	}
}

void	str_len_three(char *my_buff, char *str)
{
	char	*needle;
	char	*temp_arr;

	temp_arr = (char *)malloc(sizeof(char) * 4);
	if (str[0] != '0')
	{
		temp_arr[0] = str[0];
		temp_arr[1] = '\0';
		needle = ft_strstr(my_buff, temp_arr);
		print_aword(needle);
		write(1, " ", 1);
		needle = ft_strstr(my_buff, "100");
		print_aword(needle);
		write(1, " ", 1);
	}
	free(temp_arr);
}

void	str_len_two(char *my_buff, char *str)
{
	char	*needle;
	char	*temp_arr;

	temp_arr = (char *)malloc(sizeof(char) * 4);
	if (str[0] == '1')
	{
		needle = ft_strstr(my_buff, str);
		print_aword(needle);
	}
	else
	{
		if (str[0] != '0')
		{
			temp_arr[0] = str[0];
			temp_arr[1] = '0';
			temp_arr[2] = '\0';
			needle = ft_strstr(my_buff, temp_arr);
			print_aword(needle);
			write(1, " ", 1);
		}
	}
	free(temp_arr);
}

void	print_three_word(char *my_buff, char *str)
{
	int		str_len;
	char	*needle;

	str_len = ft_strlen(str);
	if (str_len == 0)
		return ;
	if (str_len == 1)
	{
		needle = ft_strstr(my_buff, str);
		print_aword(needle);
		return ;
	}
	if (str_len == 2)
	{
		str_len_two(my_buff, str);
		if (str[1] == '0' || str[0] == '1')
			return ;
		str++;
		if (*str == '\0')
			return ;
	}
	else if (str_len == 3)
	{
		str_len_three(my_buff, str);
		str += 1;
		if (*str == '\0')
			return ;
	}
	print_three_word(my_buff, str);
}

void	print_powers(char *my_buff, int level)
{
	char	*power;
	char	*needle;
	int		i;
	int		group;
	int		zeros;

	group = (level - 1) / 3;
	if (group <= 0)
		return ;
	zeros = group * 3;
	power = (char *)malloc(sizeof(char) * (zeros + 2));
	if (!power)
		return ;
	power[0] = '1';
	i = 1;
	while (i <= zeros)
	{
		power[i] = '0';
		i++;
	}
	power[i] = '\0';
	write(1, " ", 1);
	needle = ft_strstr(my_buff, power);
	print_aword(needle);
	free(power);
}
