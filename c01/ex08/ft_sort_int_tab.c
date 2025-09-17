/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvorley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 10:15:17 by cvorley           #+#    #+#             */
/*   Updated: 2025/09/07 10:27:22 by cvorley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i] <= tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

/*int main(void)
{
	int	tab[10] = {10, 2, 3, 5, 1, 4, 6, 9, 8, 7};
	int	size = 10;
	int	i = 0;

	printf("Before: \n");
	while(i < size)
	{
		printf("%d", tab[i]);
		i++;
	}
	ft_sort_int_tab(tab, size);
	printf("\nAfter: \n");
	i = 0;
	while(i < size)
	{
		printf("%d", tab[i]);
		i++;
	}
}*/
