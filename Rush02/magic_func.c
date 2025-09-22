/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmarsha <evmarsha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:16:51 by evmarsha          #+#    #+#             */
/*   Updated: 2025/09/21 21:16:53 by evmarsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*read_file(char *dict_name)
{
	int		f_desc;
	int		file_read;
	char	*my_buff;

	my_buff = (char *)malloc(sizeof(char) * 1024);
	if (!(my_buff))
		return (NULL);
	f_desc = open(dict_name, O_RDONLY);
	file_read = read(f_desc, my_buff, 1024);
	if (file_read == -1)
		write(1, "Dict Error\n", 11);
	else
		close(f_desc);
	return (my_buff);
}

char	*make_nbr_str(char *argv)
{
	int		str_len;
	char	*nbr_str;

	str_len = ft_strlen(argv);
	nbr_str = (char *)malloc(sizeof(char) * (str_len + 4));
	if (str_len % 3 == 2)
	{
		nbr_str[0] = '0';
		nbr_str[1] = '\0';
	}
	else if (str_len % 3 == 1)
	{
		nbr_str[0] = '0';
		nbr_str[1] = '0';
		nbr_str[2] = '\0';
	}
	ft_strcat(nbr_str, argv);
	return (nbr_str);
}

void	make_substr(char *my_buff, char *str)
{
	char	*substr;
	int		str_len;

	substr = (char *)malloc(sizeof(char) * 4);
	str_len = ft_strlen(str);
	while (str_len > 0)
	{
		write(1, " ", 1);
		my_strncpy(substr, str, 3);
		print_three_word(my_buff, substr);
		print_powers(my_buff, str_len);
		str = str + 3;
		str_len = str_len - 3;
	}
	free(substr);
}

char	*ft_atoi(char *str)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		str++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		str++;
	}
	if (str[0] == '0' && str[1] != '\0')
		return (NULL);
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			sign = -1;
		i++;
	}
	if (sign < 0)
		return (NULL);
	else
		return (str);
}
