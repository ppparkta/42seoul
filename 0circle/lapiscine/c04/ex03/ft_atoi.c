/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:15:20 by sooyang           #+#    #+#             */
/*   Updated: 2022/04/26 00:08:55 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
//#include	<stdio.h>

int	ft_atoi(char *str)
{
	long long	x;
	long long	z;
	long long	sy;

	x = 0;
	z = 0;
	sy = 1;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		x++;
	while (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			sy *= -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		z = z * 10;
		z += str[x] - '0';
		x++;
	}
	z *= sy;
	return (z);
}

/*int	main(void)
{
	int	tests;
	char *test="   --+-12345";
	tests = ft_atoi(test);
	printf("%d\n", tests);
}*/
