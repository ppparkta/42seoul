/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:00:01 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/26 00:09:02 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
//#include	<stdio.h>

void	itoa(long long n)
{
	char	one;

	if (n < 0)
	{
		write(1, "-", 1);
		itoa(-n);
		return ;
	}
	if (n >= 10)
		itoa(n / 10);
	one = n % 10 + '0';
	write(1, &one, 1);
}

void	ft_putnbr(int nb)
{
	long long	n;

	n = (long long)nb;
	itoa(nb);
}

/*int	main(void)
{
	printf("------ ex02 ------\n");
	ft_putnbr(42);
	printf("\n");
	ft_putnbr(-2147483648);
	printf("\n");
	ft_putnbr(2147483647);
	printf("\n");
	ft_putnbr(0);
	printf("\n");
	ft_putnbr(-24252);
	printf("\n\n");
}*/
