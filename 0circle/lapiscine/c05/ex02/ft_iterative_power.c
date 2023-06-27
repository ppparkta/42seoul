/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:21:49 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/30 12:24:28 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	answer;
	int	i;

	if (power < 0)
		return (0);
	answer = 1;
	i = 1;
	while (i <= power)
	{
		answer *= nb;
		i++;
	}
	return (answer);
}

/*
#include	<stdio.h>

int	main(void)
{
	printf("%d\n", ft_iterative_power(0, -1));
}*/
