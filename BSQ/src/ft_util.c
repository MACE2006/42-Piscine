/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvorley <cvorley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:24:15 by jihu              #+#    #+#             */
/*   Updated: 2025/09/24 16:45:49 by cvorley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_map	*ft_map_error(void)
{
	write (STDERR_FILENO, "map error\n", 10);
	return (NULL);
}

void	*ft_memcpy(void *dest, void *src, size_t num)
{
	unsigned char	*pointer_to_dest;
	unsigned char	*pointer_to_src;

	pointer_to_dest = (unsigned char *)dest;
	pointer_to_src = (unsigned char *)src;
	while (num--)
		*pointer_to_dest++ = *pointer_to_src++;
	return (dest);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*tmp;

	tmp = malloc (new_size);
	if (old_size < new_size)
		ft_memcpy(tmp, ptr, old_size);
	else
	{
		ft_memcpy (tmp, ptr, new_size);
	}
	free (ptr);
	return (tmp);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_atoi(char *str)
{
	int	number;
	int	sign;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		else
			sign = 1;
		str++;
	}
	else
		sign = 1;
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + *str - '0';
		str++;
	}
	return (sign * number);
}
