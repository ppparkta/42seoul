/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:26:25 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/30 12:25:01 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i * i <= nb && i < 43641)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
#include	<stdio.h>

int	main(void)
{
	printf("%d\n", ft_is_prime(15));
}*/
