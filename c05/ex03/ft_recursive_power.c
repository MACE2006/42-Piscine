/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvorley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:52:01 by cvorley           #+#    #+#             */
/*   Updated: 2025/09/18 13:45:43 by cvorley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	r;

	r = nb;
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	if (power > 1)
		return (nb * ft_recursive_power(nb, (power - 1)));
	return (r);
}

/*int	main(void)
{
	printf("%d", ft_recursive_power(2, 2));
}*/
