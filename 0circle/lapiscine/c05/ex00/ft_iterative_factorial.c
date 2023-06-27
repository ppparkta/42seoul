/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:23:10 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/30 12:24:06 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	answer;

	answer = 1;
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	i = nb;
	while (i > 0)
	{
		answer = answer * i;
		i--;
	}
	return (answer);
}

/*
#include	<stdio.h>

int	main(void)
{
	printf("%d\n", ft_iterative_factorial(5));
}*/
