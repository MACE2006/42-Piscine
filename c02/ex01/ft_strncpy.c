/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvorley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:19:28 by cvorley           #+#    #+#             */
/*   Updated: 2025/09/17 15:27:18 by cvorley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	main(void)
{
	char	dest1[100] = {"Test"};
	char	src1[] = {"Hello World!"};
        char    dest2[100] = {"Test"};
        char    src2[] = {"Hello World!"};

	int	n = 7;

	strncpy(dest1, src1, n);
	printf("%s", dest1);
	printf("\n");
	ft_strncpy(dest2, src2, n);
	printf("%s", dest2);
}
