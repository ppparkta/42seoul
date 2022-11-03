/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:51:55 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/30 12:24:16 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include	<stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

/*
int	main(void)
{
	printf("%d\n", ft_recursive_factorial(5));
}*/
